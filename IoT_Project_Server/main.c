/***********************************************************************************************//**
 * \file   main.c
 * \brief  Silicon Labs Example Project
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

/* Board headers */
#include "init_mcu.h"
#include "init_board.h"
#include "ble-configuration.h"
#include "board_features.h"

/* Bluetooth stack headers */
#include "bg_types.h"
#include "native_gecko.h"
#include "gatt_db.h"

/* Libraries containing default Gecko configuration values */
#include "em_emu.h"
#include "em_cmu.h"
#include "em_adc.h"
#include "adc.h"

/* Device initialization header */
#include "hal-config.h"

#if defined(HAL_CONFIG)
#include "bsphalconfig.h"
#else
#include "bspconfig.h"
#endif

#include "main.h"
/***********************************************************************************************//**
 * @addtogroup Application
 * @{
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup app
 * @{
 **************************************************************************************************/

#ifndef MAX_CONNECTIONS
#define MAX_CONNECTIONS 4
#endif
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
//***********************************************************************************
// Include files
//***********************************************************************************

#include "main.h"

#define TEMP_PS

//***********************************************************************************
// defined files
//***********************************************************************************


//***********************************************************************************
// global variables
//***********************************************************************************
bool mitm_enable = false;

uint8_t temp = 0;
//***********************************************************************************
// function prototypes
//***********************************************************************************


//***********************************************************************************
// functions
//***********************************************************************************

//***********************************************************************************
// main
//***********************************************************************************

/**
 * @brief  Main function
 */
int main(void)
{
  uint8 connection;
  uint32_t batteryVoltage;
  uint8_t batteryVoltagePct;
  bool notifications_enabled = false;

  // Initialize device
  initMcu();

  // Initialize board
  initBoard();

  // Initialize application
  initApp();

  // Initialize clocks
  cmu_init();

  /* Initialize GPIO */
  gpio_init();

  // Initialize stack
  gecko_init(&config);

  // Initialize LETIMER0
  letimer0_init();

  // Initialize I2C0
  i2c0_init();

  // Initialize ADC for battery service
  InitADCforSupplyMeasurement();

  // Initialize LCD functions
  LCD_init();

  LCD_clear_and_display("Sensor Server\n");

  // Initialize proximity sensor
//  prox_init();
  //  prox_read();

  uint8_t random;
  uint8_t buffer[5];
  uint8_t buf[3] = {0,1,2};

  //Scheduler code
  while (1)
  {
  /* Event pointer for handling events */
	 struct gecko_cmd_packet* evt;

	 // Variable to store dBm
	 int8_t rssi;

	 /* Check for stack event. */
	 evt = gecko_wait_event();

	 /* Handle events */
	 switch (BGLIB_MSG_ID(evt->header)) {
	   /* This boot event is generated when the system boots up after reset.
		* Do not call any stack commands before receiving the boot event.
		* Here the system is set to start advertising immediately after boot procedure. */
	   case gecko_evt_system_boot_id:
			gecko_cmd_sm_delete_bondings();

			  /* MITM Operation */
			gecko_cmd_sm_configure(BONDING_MITM_PROTECTION | BONDING_ENCRYPTION |
				SECURE_CONNECTION | NO_BONDING,sm_io_capability_displayyesno);

			gecko_cmd_sm_set_bondable_mode(1);

			gecko_cmd_hardware_set_soft_timer(BATTERY_READ_INTERVAL, //interval
			                                           ADC_READ, //handle
			                                          REPEATING); //mode – repeating

			/* Set advertising parameters. 100ms advertisement interval. All channels used.
			 * The first two parameters are minimum and maximum advertising interval, both in
			 * units of (milliseconds * 1.6). The third parameter '7' sets advertising on all channels. */
			gecko_cmd_le_gap_set_adv_parameters(ADVERTISING_PERIOD, ADVERTISING_PERIOD, CHANNELS);

			/* Start general advertising and enable connections. */
			gecko_cmd_le_gap_set_mode(le_gap_general_discoverable, le_gap_undirected_connectable);
		 break;

	   case gecko_evt_le_connection_opened_id:
		   BLE_connection = evt->data.evt_le_connection_opened.connection;
		   gecko_cmd_sm_increase_security(BLE_connection);
		   /* Set default connection parameters
			* 75ms min & max interval (75ms/1.25ms)
			* Slave latency = 6 (450ms / 75ms)
			* timeout = 1100 > (1 + slave_latency) * max_interval * 2
			*/
//		  gecko_cmd_le_connection_set_parameters(BLE_connection, CONN_MIN_INTERVAL, CONN_MAX_INTERVAL, SLAVE_LAT, TIMEOUT);
	   		   break;

	   case gecko_evt_sm_confirm_passkey_id:
		   /* Passkey generated and displayed */
		   mitm_enable = true;
		   LCD_passkey_display(evt->data.evt_sm_confirm_passkey.passkey);
		   break;

		case gecko_evt_sm_bonded_id:
			temp = 1;
			LCD_clear_and_display("Master Bonded!\n");
			break;

		case gecko_evt_sm_bonding_failed_id:
			LCD_clear_and_display("Master Error!\n");
			break;

	   case gecko_evt_le_connection_closed_id:

		 /* Check if need to boot to dfu mode */
		 if (boot_to_dfu) {
		   /* Enter to DFU OTA mode */
		   gecko_cmd_system_reset(2);
		 } else {
		   /* Restart advertising after client has disconnected */
		   gecko_cmd_le_gap_set_mode(le_gap_general_discoverable, le_gap_undirected_connectable);
		 }
		 break;

	   case gecko_evt_system_external_signal_id:
		   if(evt->data.evt_system_external_signal.extsignals & PROXIMITY_SENSOR_EVENT)
		   {
//			   GPIO_PinOutSet(LED1_port, LED1_pin);
		   	   uint8_t stat = read8((uint8_t)PROX_INTERRUPT_STATUS_REG);
	   		   uint16_t result = read16((uint8_t)PROX_MEASURE_RESULT_HIGH_BYTE_REG);

		   	   if(stat)
		   	   {
		   		   uint16_t result = read16((uint8_t)PROX_MEASURE_RESULT_HIGH_BYTE_REG);
				   GRAPHICS_Clear();
				   GRAPHICS_AppendString("Threshold ");
				   GRAPHICS_AppendString("Exceeded\n");
				   GRAPHICS_Update();
		   	   }
		   	   else
		   	   {
		   		   GRAPHICS_Clear();
		   		   GRAPHICS_AppendString("Within ");
				   GRAPHICS_AppendString("Threshold\n");
				   GRAPHICS_Update();
		   	   }

//			   GPIO_PinOutClear(LED1_port, LED1_pin);
		   }
//		   if(evt->data.evt_system_external_signal.extsignals & LETIMER_EVENT)
//		   {
//			   memset(buffer, 0, 20);
//			   random = rand();
//			   sprintf(buffer,"Number:%d\n", random);
//			   GRAPHICS_AppendString(buffer);
//			   GRAPHICS_Update();
//			   GRAPHICS_Clear();
//		   }
//		   else if(evt->data.evt_system_external_signal.extsignals & POR_EVENT)
//			   LETIMER_event_handler();

		   break;

	   case gecko_evt_hardware_soft_timer_id:
			if(evt->data.evt_hardware_soft_timer.handle == ADC_READ)
			{
				static int temp = 0;;
			  ADC_Start(ADC0,adcStartSingle );
			  batteryVoltage = readSupplyVoltage();
			  batteryVoltagePct = (batteryVoltage/3300.0)*100;
			  memset(buffer, 0, 5);
			  sprintf(buffer, "%d%%\n", batteryVoltagePct);
//			  GRAPHICS_Clear();
			  GRAPHICS_AppendString(buffer);
			  GRAPHICS_Update();
			  if(temp < 70)
			  {
				  gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_battery_value, 1, &batteryVoltagePct);
				  gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_product_count, 2, buf);
			  }
			  temp++;
			}
			break;

	  case gecko_evt_gatt_server_user_read_request_id:
		   if(evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_battery_value) {
//			   gecko_cmd_gatt_server_send_user_read_response( evt-> data.evt_gatt_server_user_read_request.connection, evt->data.evt_gatt_server_user_read_request.characteristic, 0, 1, &batteryVoltagePct);
//			   gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_battery_level, 1,  &batteryVoltagePct);
		   }
		   break;

	  case gecko_evt_le_connection_rssi_id:
		   rssi = evt->data.evt_le_connection_rssi.rssi;
		   gecko_cmd_system_halt(1);

		   if(rssi > -35)
			   gecko_cmd_system_set_tx_power(TX_MIN_dB);
		   else if (rssi < -35 && rssi > -45 )
			   gecko_cmd_system_set_tx_power(-200);
		   else if (rssi < -45 && rssi > -55 )
			   gecko_cmd_system_set_tx_power(-150);
		   else if (rssi < -55 && rssi > -65)
			   gecko_cmd_system_set_tx_power(-50);
		   else if (rssi < -65 && rssi > -75)
			   gecko_cmd_system_set_tx_power(0);
		   else if (rssi < -75 && rssi > -85)
			   gecko_cmd_system_set_tx_power(50);
		   else if (rssi < -85)
			   gecko_cmd_system_set_tx_power(TX_MAX_dB);
		   gecko_cmd_system_halt(0);
		   break;

	   /* Events related to OTA upgrading
	  ----------------------------------------------------------------------------- */
	   /* Check if the user-type OTA Control Characteristic was written.
		* If ota_control was written, boot the device into Device Firmware Upgrade (DFU) mode. */
	   case gecko_evt_gatt_server_user_write_request_id:

		   if (evt->data.evt_gatt_server_user_write_request.characteristic == gattdb_ota_control) {
		   /* Set flag to enter to OTA mode */
		   boot_to_dfu = 1;
		   /* Send response to Write Request */
		   gecko_cmd_gatt_server_send_user_write_response(
			 evt->data.evt_gatt_server_user_write_request.connection,
			 gattdb_ota_control,
			 bg_err_success);

		   /* Close connection to enter to DFU OTA mode */
		   gecko_cmd_endpoint_close(evt->data.evt_gatt_server_user_write_request.connection);
		 }
		 break;

	   default:
		 break;
	 }
  }
}

/** @} (end addtogroup app) */
/** @} (end addtogroup Application) */
