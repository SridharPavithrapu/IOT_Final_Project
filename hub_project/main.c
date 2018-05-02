/***********************************************************************************************//**
 * \file   main.c
 * \brief  Silicon Labs Empty Example Project
 *
 * This example demonstrates the bare minimum needed for a Blue Gecko C application
 * that allows Over-the-Air Device Firmware Upgrading (OTA DFU). The application
 * starts advertising after boot and restarts advertising after a connection is closed.
 ***************************************************************************************************
 * <b> (C) Copyright 2016 Silicon Labs, http://www.silabs.com</b>
 ***************************************************************************************************
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 **************************************************************************************************/

//***********************************************************************************
// Include files
//***********************************************************************************
#include "main.h"

/* Board headers */
#include "init_mcu.h"
#include "init_board.h"
#include "init_app.h"
#include "ble-configuration.h"
#include "board_features.h"

/* Bluetooth stack headers */
#include "bg_types.h"
#include "native_gecko.h"
#include "gatt_db.h"

/* Libraries containing default Gecko configuration values */
#include "em_emu.h"
#include "em_cmu.h"

/* Device initialization header */
#include "hal-config.h"

#if defined(HAL_CONFIG)
#include "bsphalconfig.h"
#else
#include "bspconfig.h"
#endif

/***********************************************************************************************//**
 * @addtogroup Application
 * @{
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup app
 * @{
 **************************************************************************************************/

#ifndef MAX_CONNECTIONS
#define MAX_CONNECTIONS 2
#endif

#define LETIMER0_COMP0_EVENT (0x01)


/* Bluetooth connection handle */
uint8_t _server_conn_handle = 0xFF;
uint8_t _remote_client_conn_handle = 0xFF;

bool mitm_server_enable;
bool mitm_client_enable;

static int services_characteristics_count;

bool master_connected;
bool server_connected;

/* Buffer to print on the LCD */
char print_buffer[50];
char dma_buffer[50];
const LDMA_TransferCfg_t periTransferRx = LDMA_TRANSFER_CFG_PERIPHERAL( ldmaPeripheralSignal_USART0_TXEMPTY);
LDMA_Descriptor_t xfer = LDMA_DESCRIPTOR_SINGLE_M2P_BYTE( &dma_buffer[0], &USART0->TXDATA, sizeof(dma_buffer));


uint8_t bluetooth_stack_heap[DEFAULT_BLUETOOTH_HEAP(MAX_CONNECTIONS)];

// Gecko configuration parameters (see gecko_configuration.h)
static const gecko_configuration_t config = {
  .config_flags = 0,
  .sleep.flags = SLEEP_FLAGS_DEEP_SLEEP_ENABLE,
  .bluetooth.max_connections = MAX_CONNECTIONS,
  .bluetooth.heap = bluetooth_stack_heap,
  .bluetooth.heap_size = sizeof(bluetooth_stack_heap),
  .bluetooth.sleep_clock_accuracy = 100, // ppm
  .gattdb = &bg_gattdb_data,
  .ota.flags = 0,
  .ota.device_name_len = 3,
  .ota.device_name_ptr = "OTA",
#if (HAL_PA_ENABLE) && defined(FEATURE_PA_HIGH_POWER)
  .pa.config_enable = 1, // Enable high power PA
  .pa.input = GECKO_RADIO_PA_INPUT_VBAT, // Configure PA input to VBAT
#endif // (HAL_PA_ENABLE) && defined(FEATURE_PA_HIGH_POWER)
};

// Flag for indicating DFU Reset must be performed
uint8_t boot_to_dfu = 0;

/**
 * @brief  Processes advertisement packets looking for HTM service
 */
int process_scan_response(struct gecko_msg_le_gap_scan_response_evt_t *pResp)
{
	/* Decoding advertising packets is done here. The list of AD types can be found
	 * at: https://www.bluetooth.com/specifications/assigned-numbers/Generic-Access-Profile */

	int i=0;
    int ad_match_found = 0;
	int ad_len;
    int ad_type;


    while (i < (pResp->data.len - 1))
    {
        ad_len  = pResp->data.data[i];
        ad_type = pResp->data.data[i+1];

		if (ad_type == 0x06 || ad_type == 0x07)
		{
			/* ad_type 0x06 = Incomplete List of 128-bit Service Class UUIDs */
			/* ad_type 0x07 = Complete List of 128-bit Service Class UUIDs */
			if(memcmp(product_serviceUUID, &(pResp->data.data[i+2]),16) == 0)
			{
				ad_match_found = 1;
				break;
			}
		}

        /* Jump to next AD record */
        i = i + ad_len + 1;
    }

    return(ad_match_found);
}

void letimer0_comp0_handler()
{
	if((master_connected == false) && (server_connected == true))
	{
		/* Timer has timed out -  Connecting to remote client */

		/* Start general advertising and enable connections. */
		gecko_cmd_le_gap_set_adv_parameters(160,160,7);
		gecko_cmd_le_gap_start_advertising(0,le_gap_general_discoverable, le_gap_undirected_connectable);
	}
}

/**
 * @brief  Main function
 */
int main(void)
{
  /* Initialize device */
  initMcu();

  /* Initialize board */
  initBoard();

  /* Initialize application */
  initApp();

  cmu_init();

  /* GPIO init */
  gpio_init();

  /* Initialize UART */
  uart_init();

  /* Initialize LCD */
  lcd_initialize();

  /* Initialize LDMA */
  ldma_init();

  /* Initialize LETIMER */
  letimer0_init();

  /* Initialize stack */
  gecko_init(&config);

  /* Printing welcome string on LCD */
  memset(dma_buffer, '\0', sizeof(dma_buffer));
  strcpy(dma_buffer, "Smart Inventory!\n\r     HUB\n\r");
  lcd_clear_print("Smart Inventory!\n     HUB\n");
  LDMA_StartTransfer( 0, (void*)&periTransferRx, (void*)&xfer );


#ifdef UART_TEST
  char sss_buffer[50];
  memset(sss_buffer,'\0',sizeof(sss_buffer));
  strcpy(sss_buffer,"Smart");
  for(int i=0;i<strlen(sss_buffer);i++)
  {
	  USART_Tx(USART0, sss_buffer[i]);
  }

#endif



  uint8_t ps_flag = 0;
  uint8_t default_data = 0;
  ps_load_object(PS_FLAG_KEY, &ps_flag, sizeof(ps_flag));
  if(!ps_flag)
  {
	  ps_flag = 1;
	  ps_save_object(PS_FLAG_KEY, &ps_flag, sizeof(ps_flag));
	  ps_save_object(PRODUCT1_BATTERY_MEMORY, &default_data, sizeof(default_data));
	  ps_save_object(PRODUCT1_PRODUCT_MEMORY, &default_data, sizeof(default_data));
  }

  while (1) {

	/* Event pointer for handling events */
	struct gecko_cmd_packet* evt;

	/* Check for stack event. */
	evt = gecko_wait_event();

	/* Handle events */
	switch (BGLIB_MSG_ID(evt->header)) {

		/* This boot event is generated when the system boots up after reset.
		* Do not call any stack commands before receiving the boot event.
		* Here the system is set to start advertising immediately after boot procedure. */
		case gecko_evt_system_boot_id:
			/* Connected as client */
			master_connected = false;
			server_connected = false;
			mitm_server_enable = false;
			mitm_client_enable = false;

			gecko_cmd_sm_delete_bondings();

			/* MITM Operation */
			gecko_cmd_sm_configure(BONDING_MITM_PROTECTION | BONDING_ENCRYPTION |
					SECURE_CONNECTION | NO_BONDING,sm_io_capability_displayyesno);

			gecko_cmd_sm_set_bondable_mode(BONDING_VAR);

			gecko_cmd_le_gap_set_scan_parameters(100, 100, 1);

			/* Start Scanning */
			/* Initially acting as a client */
			gecko_cmd_le_gap_discover(le_gap_discover_generic);

			/* Running the software timer for connecting to client for every 5 seconds */
			//gecko_cmd_hardware_set_soft_timer(164000, 0 , 0);

		break;

		case gecko_evt_le_gap_scan_response_id:
			/* Validating for required server connection */
			if(process_scan_response(&(evt->data.evt_le_gap_scan_response)) > 0)
			{
				/* We are going to create the last supported connections so let's advertise as non-connectable */
				gecko_cmd_le_gap_set_mode(le_gap_non_discoverable, le_gap_non_connectable);

				lcd_clear_print("Connecting Server\n");

				/* Match found - stop scanning */
				gecko_cmd_le_gap_end_procedure();

				gecko_cmd_le_gap_open(evt->data.evt_le_gap_scan_response.address, evt->data.evt_le_gap_scan_response.address_type);

			}
		break;

		case gecko_evt_le_connection_opened_id:
			lcd_clear_print("MITM Start\n");

			if(evt->data.evt_le_connection_opened.master == 0) {
				/* If master device is connected - we are currently slave/server*/

				lcd_print("For Remote Client\n");

				/* Storing the server connection handle */
				_remote_client_conn_handle = evt->data.evt_le_connection_opened.connection;

				/* Increasing the security */
				gecko_cmd_sm_increase_security(_remote_client_conn_handle);
			}
			else
			{
				/* If master device is not connected - we are currently master/client*/
				lcd_print("For Server\n");

				/* Storing the server connection handle */
				_server_conn_handle = evt->data.evt_le_connection_opened.connection;

				/* Increasing the security */
				gecko_cmd_sm_increase_security(_server_conn_handle);
			}
		break;

		case gecko_evt_sm_confirm_passkey_id:
			if(evt->data.evt_sm_confirm_passkey.connection == _server_conn_handle)
			{
				/* Passkey generated and displayed */
				lcd_passkey_display(0,evt->data.evt_sm_confirm_passkey.passkey);
				mitm_server_enable = true;
			}
			else if(evt->data.evt_sm_confirm_passkey.connection == _remote_client_conn_handle)
			{
				/* Passkey generated and displayed */
				lcd_passkey_display(1,evt->data.evt_sm_confirm_passkey.passkey);
				mitm_client_enable = true;
			}
		break;

		case gecko_evt_sm_bonded_id:
			if(evt->data.evt_sm_confirm_passkey.connection == _server_conn_handle)
			{
				lcd_clear_print("Slave Bonded!\n");
				services_characteristics_count = 0;
				server_connected = true;
				/* Requesting service handle for product UUID */
				gecko_cmd_gatt_discover_primary_services_by_uuid(_server_conn_handle, 16, product_serviceUUID);
			}
			else if(evt->data.evt_sm_confirm_passkey.connection == _remote_client_conn_handle)
			{
				lcd_clear_print("Client Bonded!\n");
				/* Client connected successfully */
				master_connected = true;
			}
		break;

		case gecko_evt_sm_bonding_failed_id:
			if(evt->data.evt_sm_bonding_failed.connection == _server_conn_handle)
			{
				lcd_clear_print("Slave\nConnection Failed!\n");

				/* Server connection failed, so start scanning */
				gecko_cmd_le_gap_discover(le_gap_discover_generic);
			}
			else if(evt->data.evt_sm_bonding_failed.connection == _remote_client_conn_handle)
			{
				lcd_clear_print("Client\nConnection Failed!\n");

				/* Client connection failed, so start advertising */
				gecko_cmd_le_gap_start_advertising(0,le_gap_general_discoverable, le_gap_undirected_connectable);
				master_connected = false;
			}
		break;

		case gecko_evt_gatt_service_id:
			if(evt->data.evt_gatt_service.uuid.len == 16)
			{
				if(memcmp(product_serviceUUID, evt->data.evt_gatt_service.uuid.data,16) == 0)
				{
					/* Storing the service handle for product service */
					_product_service_handle = evt->data.evt_gatt_service.service;
					lcd_clear_print("product service");
				}
				if(memcmp(battery_serviceUUID, evt->data.evt_gatt_service.uuid.data,16) == 0)
				{
					/* Storing the service handle for battery service */
					_battery_service_handle = evt->data.evt_gatt_service.service;
					lcd_print("battery service");
				}
			}
			else
			{
				/* Invalid service id is received */
			}
		break;

		case gecko_evt_gatt_characteristic_id:

			if(evt->data.evt_gatt_characteristic.uuid.len == 16)
			{
				if(memcmp(product_charUUID, evt->data.evt_gatt_characteristic.uuid.data,16) == 0)
				{
					/* Storing the characteristic handle for product service */
					_product_char_handle = evt->data.evt_gatt_characteristic.characteristic;
					lcd_print("product char");
				}
				if(memcmp(battery_charUUID, evt->data.evt_gatt_characteristic.uuid.data,16) == 0)
				{
					/* Storing the characteristic handle for product service */
					_battery_char_handle = evt->data.evt_gatt_characteristic.characteristic;
					lcd_print("battery char");
				}
			}
			else
			{
				/* Invalid characteristic id is received */
			}
			break;

		case gecko_evt_gatt_procedure_completed_id:
			if(services_characteristics_count == 0)
			{
				gecko_cmd_gatt_discover_characteristics_by_uuid(_server_conn_handle, _product_service_handle,16,product_charUUID);
				services_characteristics_count++;
			}
			else if(services_characteristics_count == 1)
			{
				gecko_cmd_gatt_discover_primary_services_by_uuid(_server_conn_handle, 16, battery_serviceUUID);
				services_characteristics_count++;
			}
			else if(services_characteristics_count == 2)
			{
				gecko_cmd_gatt_discover_characteristics_by_uuid(_server_conn_handle, _battery_service_handle,16,battery_charUUID);
				services_characteristics_count++;
			}
			else if(services_characteristics_count == 3)
			{
				gecko_cmd_gatt_set_characteristic_notification(_server_conn_handle, _product_char_handle, gatt_notification);
				/* characteristics count increment to make sure in the correct state machine */
				services_characteristics_count++;
			}
			else if(services_characteristics_count == 4)
			{
				gecko_cmd_gatt_set_characteristic_notification(_server_conn_handle, _battery_char_handle, gatt_notification);
				/* characteristics count increment to make sure in the correct state machine */
				services_characteristics_count++;
			}
			else
			{
				/* Done with state machine */
				lcd_print("Done with state");
				memset(print_buffer,'\0',sizeof(print_buffer));
				sprintf(print_buffer,"%ld,%d\n",_product_service_handle, _product_char_handle);
				lcd_print(print_buffer);
				memset(print_buffer,'\0',sizeof(print_buffer));
				sprintf(print_buffer,"%ld,%d\n",_battery_service_handle, _battery_char_handle);
				lcd_print(print_buffer);
			}
		break;


			case gecko_evt_gatt_characteristic_value_id:
				if((evt->data.evt_gatt_characteristic_value.characteristic == _product_char_handle))
				{
					/* Printing the received product count on LCD */
					memcpy(product_count_received, evt->data.evt_gatt_characteristic_value.value.data,
																					evt->data.evt_gatt_characteristic_value.value.len);
					if(evt->data.evt_gatt_characteristic_value.value.len == 2)
					{
						memset(print_buffer,'\0',sizeof(print_buffer));
						memset(dma_buffer,'\0',sizeof(dma_buffer));
						sprintf(print_buffer,"ID: %d\ncount:%d\n",product_count_received[0],product_count_received[1]);
						lcd_clear_print(print_buffer);

						gecko_cmd_gatt_send_characteristic_confirmation(_server_conn_handle);

						if(master_connected == 1)
						{
							if(product_count_received[0] == 1)
							{
								uint8_t remote_notification_buffer[2];
								remote_notification_buffer[0] = product_count_received[0];

								/* Loading the product count value from persitent memory */
								ps_load_object(PRODUCT1_PRODUCT_MEMORY, &product_count_received[1], sizeof(product_count_received[1]));

								remote_notification_buffer[1] = product_count_received[1] + 1;
								ps_save_object(PRODUCT1_PRODUCT_MEMORY, &remote_notification_buffer[1], sizeof(remote_notification_buffer[1]));
								/* Sending notification to remote client */
								gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_remote_product_count,
										2, remote_notification_buffer);
							}
						}
						sprintf(dma_buffer,"ID: %d\n\r     Count:%d\n\r",product_count_received[0],product_count_received[1]);
						LDMA_StartTransfer( 0, (void*)&periTransferRx, (void*)&xfer );

					}
					else
					{
						/* Invalid value received*/
						memset(print_buffer,'\0',sizeof(print_buffer));
						sprintf(print_buffer,"Invalid value\n");
						lcd_clear_print(print_buffer);
						gecko_cmd_gatt_send_characteristic_confirmation(_server_conn_handle);
					}

				}
				else if(evt->data.evt_gatt_characteristic_value.characteristic == _battery_char_handle)
				{
					/* Printing the battery status on LCD */
					memcpy(battery_status_received, evt->data.evt_gatt_characteristic_value.value.data,
																					evt->data.evt_gatt_characteristic_value.value.len);
					if(evt->data.evt_gatt_characteristic_value.value.len == 2)
					{
						memset(print_buffer,'\0',sizeof(print_buffer));
						memset(dma_buffer,'\0',sizeof(dma_buffer));
						sprintf(print_buffer,"ID:%d\nstatus:%d\n",battery_status_received[0],battery_status_received[1]);
						lcd_clear_print(print_buffer);
						gecko_cmd_gatt_send_characteristic_confirmation(_server_conn_handle);


						if(master_connected == 1)
						{
							uint8_t remote_notification_buffer[2];
							remote_notification_buffer[0] = battery_status_received[0];

							remote_notification_buffer[1] = battery_status_received[1];

							/* Sending notification to remote client */
							gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_remote_battery_value,
																					2, remote_notification_buffer);
						}
						sprintf(dma_buffer,"ID: %d\n\r     Status:%d\n\r",battery_status_received[0],battery_status_received[1]);
						LDMA_StartTransfer( 0, (void*)&periTransferRx, (void*)&xfer );
					}
				}
				else
				{
					/* Invalid value received*/
					memset(print_buffer,'\0',sizeof(print_buffer));
					sprintf(print_buffer,"Invalid status\n");
					lcd_print(print_buffer);
					gecko_cmd_gatt_send_characteristic_confirmation(_server_conn_handle);
				}
			break;

			case gecko_evt_le_connection_closed_id:
				/* Check if need to boot to dfu mode */
				if (boot_to_dfu)
				{
					/* Enter to DFU OTA mode */
					gecko_cmd_system_reset(2);
				}

				if(evt->data.evt_le_connection_closed.connection == _server_conn_handle)
				{
					lcd_clear_print("Slave disconnected\n");

					/* Server disconnected, so start scanning */
					gecko_cmd_le_gap_discover(le_gap_discover_generic);
					server_connected = false;
				}
				else if(evt->data.evt_le_connection_closed.connection == _remote_client_conn_handle)
				{
					lcd_clear_print("Client disconnected\n");

					/* Client disconnected, so start advertising */
					gecko_cmd_le_gap_start_advertising(0,le_gap_general_discoverable, le_gap_undirected_connectable);
					master_connected = false;
				}
			break;

			case gecko_evt_hardware_soft_timer_id:

				if((master_connected == false) && (server_connected == true))
				{
					/* Timer has timed out -  Connecting to remote client */

					/* Start general advertising and enable connections. */
					gecko_cmd_le_gap_set_adv_parameters(160,160,7);
					gecko_cmd_le_gap_start_advertising(0,le_gap_general_discoverable, le_gap_undirected_connectable);
				}

			break;

			 /* Handling external signals */
			case gecko_evt_system_external_signal_id:
				if (evt->data.evt_system_external_signal.extsignals & LETIMER0_COMP0_EVENT)
				{
					letimer0_comp0_handler();
				}
			break;

			/* Events related to OTA upgrading */
			/* Check if the user-type OTA Control Characteristic was written.
			* If ota_control was written, boot the device into Device Firmware Upgrade (DFU) mode. */
			case gecko_evt_gatt_server_user_write_request_id:

				if (evt->data.evt_gatt_server_user_write_request.characteristic == gattdb_ota_control)
				{
					/* Set flag to enter to OTA mode */
					boot_to_dfu = 1;
					/* Send response to Write Request */
					gecko_cmd_gatt_server_send_user_write_response(
								evt->data.evt_gatt_server_user_write_request.connection,
								gattdb_ota_control,
								bg_err_success);

					/* Close connection to enter to DFU OTA mode */
					gecko_cmd_le_connection_close(evt->data.evt_gatt_server_user_write_request.connection);
				}
			break;

			default:
				/* Invalid event received */
			break;
		}
	}
}

/** @} (end addtogroup app) */
/** @} (end addtogroup Application) */
