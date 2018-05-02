/********************************************************************************************************************
* File Name 	  : letimer.c
* File Description: This file contains the routines for LETIMER0 initialization and ISR
* Author		  : Rishi Soni
* Date			  : 01/29/2018
* Compiler : arm-none-eabi-gcc
* Linker   : arm-none-eabi-ld
* Debugger : gdb
********************************************************************************************************************
 * <b> (C) Copyright 2016 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************************************************
 * This file contains licensed libraries under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 ******************************************************************************************************************/

#include "main.h"

/** Setup the LETIMER0 peripherals, with automatically calculating the COMP0 and COMP1
 *
 * Checks the minimum energy state, defined as a macro in "main.h". Defines the blockSleepMode()
 * for the defined energy mode.
 *
 * UF interrupt is enabled
 */
void letimer0_init(void)
{
	uint32_t count_total_period;
	uint32_t count_reset_period;

	//Disable LETIMER before struct initialization
	LETIMER_Enable(LETIMER0, false);

	//Structure LETIMER_Init_TypeDef init
	LETIMER_Init_TypeDef LETIMER0_Params =
	{
			false,				// Enable timer when init complete
			false,				// debugRUN
			true,				// comp0Top
			false, 				// bufTop
			0,					// output 0
			0,					// output 1
			letimerUFOANone,  	// No action on underflow on output 0.
			letimerUFOANone,  	// No action on underflow on output 1.
			letimerRepeatFree 	// Count until stopped by SW.
	};

	//Initialize LETIMER0 using the populated struct above
	LETIMER_Init(LETIMER0, &LETIMER0_Params);

	count_total_period = CMU_ClockFreqGet(cmuClock_LETIMER0) * TOTAL_PERIOD;
	count_reset_period = CMU_ClockFreqGet(cmuClock_LETIMER0) * RESET_PERIOD;
	LETIMER_CompareSet(LETIMER0, 0, count_total_period);
	LETIMER_CompareSet(LETIMER0, 1, count_total_period - count_reset_period);


	// Wait till LETIMER0 is ready
	while(LETIMER0->SYNCBUSY);

	//Clear all pending interrupts
	LETIMER_IntClear(LETIMER0,LETIMER_IFC_REP1 | LETIMER_IFC_REP0 | LETIMER_IFC_UF | LETIMER_IFC_COMP1 | LETIMER_IFC_COMP0);

	//Enabling COMP1 and UF interrupts
	LETIMER_IntEnable(LETIMER0, LETIMER_IEN_COMP0 |LETIMER_IEN_COMP1);

	//Enable LETIMER interrupt in NVIC
	NVIC_EnableIRQ(LETIMER0_IRQn);

	//Block sleep modes
//	switch(MIN_MODE)
//	{
//		case 0:
//			blockSleepMode(EM0);
//			break;
//		case 1:
//			blockSleepMode(EM1);
//			break;
//		case 2:
//			blockSleepMode(EM2);
//			break;
//		case 3:
//			blockSleepMode(EM3);
//			break;
//		case 4:
//			blockSleepMode(EM4);
//			break;
//	}

	//Enable LETIMER
//	LETIMER_Enable(LETIMER0, true);
}

/** Load Power Management for temperature sensor
 *
 * Switch ON the temp sensor, read the temperature through the I2C bus.
 * Switch ON LED1 if temperature is below 15C
 *
 * UF interrupt is enabled
 */
void LETIMER_event_handler(void)
{
	uint32_t ps_temp_thresh, temp_thresh;
	i2c0_power(true);
	uint16_t temp_val = temp_read();
	float orig_temp = ((175.72 * temp_val)/65536)  - 46.85;

//	if(1)
//	{
		ps_load_object((uint16_t)PS_TEMP_KEY, (void*)&ps_temp_thresh, sizeof(ps_temp_thresh));
		temp_thresh = ps_temp_thresh;
//	}
//	else
//		temp_thresh = TEMP_THRESHOLD;

	if(orig_temp < temp_thresh)
		GPIO_PinOutSet(LED1_port, LED1_pin);
	else
		GPIO_PinOutClear(LED1_port, LED1_pin);
	i2c0_power(false);

	// Creating Bluetooth packet
	int32_t temperature = ((temp_val * 21965L) >> 13) - 46850;
	uint8_t flags = 0x00;   /* HTM flags set as 0 for Celsius, no time stamp and no temperature type. */
	uint8_t htmTempBuffer[5]; /* Stores the temperature data in the Health Thermometer (HTM) format. */
	uint8_t *p = htmTempBuffer; /* Pointer to HTM temperature buffer needed for converting values to bitstream. */

	/* Convert flags to bitstream and append them in the HTM temperature data buffer (htmTempBuffer) */
	UINT8_TO_BITSTREAM(p, flags);

	uint32_t tempData = FLT_TO_UINT32(temperature, -3);
	/* Convert temperature to bitstream and place it in the HTM temperature data buffer (htmTempBuffer) */
	UINT32_TO_BITSTREAM(p, tempData);
	// Send data over Bluetooth
//	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_temperature_measurement, 5, htmTempBuffer);


//	gecko_cmd_le_connection_get_rssi(BLE_connection);

//	unblockSleepMode(EM1);
}

/** Setup the LETIMER0 IRQ handler
 *
 * Clears COMP0 interrupt flag. LED ON for ON_PERIOD
 *
 * Clears UF interrupt flag. LED OFF for (TOTAL_PERIOD - ON_PERIOD)
 */
void LETIMER0_IRQHandler(void)
{
	// Disable interrupts to avoid nesting
	CORE_ATOMIC_IRQ_DISABLE();

	//COMP0 interrupt
	if(LETIMER0->IF & LETIMER_IF_COMP0)
	{
		//Disable the COMP0 interrupt
		LETIMER0->IFC |= LETIMER_IF_COMP0;
		// Setting the LETIMER timer event flag in Blue Gecko Bluetooth event stack
//		gecko_external_signal(LETIMER_EVENT);

	}
	// 80ms event
	else if(LETIMER0->IF & LETIMER_IF_COMP1)
	{
		LETIMER0->IFC |= LETIMER_IF_COMP1;
//		gecko_external_signal(POR_EVENT);
	}
	// Re-enable interrupts
	CORE_ATOMIC_IRQ_ENABLE();

}
