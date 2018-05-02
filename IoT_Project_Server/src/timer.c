/********************************************************************************************************************
* File Name 	  : timer.c
* File Description: This file contains the routines for TIMER0 initialization, ISR and TIMER0 start
* Author		  : Rishi Soni
* Date			  : 02/11/2018
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

/** Setup the TIMER0 peripheral, with one-shot timer mode.
 *
 * Created for Power-On Reset (POR) (80ms) of the Sensor Enable for LPM
 *
 * OF interrupt is enabled
 */
void timer0_init(void)
{
	// Initialize TIMER0 parameters
	const TIMER_Init_TypeDef Timer_Params =
	{

		   false,  					// Do not start counting when init completes
		   false,  					// Counter does not keep running during debug halt
		   timerPrescale1024,		// Prescaling factor, if HFPER clock used.
		   timerClkSelHFPerClk, 	// HFPER Clock selected
		   timerInputActionNone, 	// No action on falling input edge
		   timerInputActionNone,	// No action on rising input edge
		   timerModeUp,				// Up counting mode
		   false,					// DMA request clear on not active
		   false,					// No X2 or X4 quadrature decode mode
		   true,					// Enable One-shot
		   false	   				// Timer does not start/stop/reload by other timers
	};

	// Initialize TIMER0, but don't start it
	TIMER_Init(TIMER0, &Timer_Params);
	// Clear pending interrupts
	TIMER_IntClear(TIMER0, TIMER_IFC_ICBOF3 | TIMER_IFC_ICBOF2 | TIMER_IFC_ICBOF1 | \
			TIMER_IFC_ICBOF0 | TIMER_IFC_CC3 | TIMER_IFC_CC2 | TIMER_IFC_CC1 | \
			TIMER_IFC_CC0| TIMER_IFC_DIRCHG | TIMER_IFC_UF | TIMER_IFC_OF);
	// Enable overflow interrupt
	TIMER_IntEnable(TIMER0, TIMER_IEN_OF);
//	TIMER_TopSet(TIMER0, 0x22);
//	TIMER_CounterSet(TIMER0, 0x00);

	// Enable NVIC IRQ for TIMER0
	NVIC_EnableIRQ(TIMER0_IRQn);
	// Set high priority for timer0 interrupt
//	NVIC_SetPriority(TIMER0_IRQn, 2);
}


/** TIMER0 interrupt service routine
 *
 * Disable timer after running once
 */
void TIMER0_IRQHandler(void)
{
	CORE_ATOMIC_IRQ_DISABLE();                       								//Disable interrupts to avoid nesting
	TIMER_IntClear(TIMER0, TIMER_IFC_ICBOF3 | TIMER_IFC_ICBOF2 | TIMER_IFC_ICBOF1 | \
				TIMER_IFC_ICBOF0 | TIMER_IFC_CC3 | TIMER_IFC_CC2 | TIMER_IFC_CC1 | \
				TIMER_IFC_CC0| TIMER_IFC_DIRCHG | TIMER_IFC_UF | TIMER_IFC_OF);

	//Clear TIMER0 overflow interrupt
	if(TIMER0->IF & TIMER_IF_OF)
	{
		TIMER0->IFC |= TIMER_IF_OF;
	}

	// Set flag after 80ms
	flag = 1;

	// Disable TIMER0
	TIMER_Enable(TIMER0, false);

	// Setting the TIMER0 timer event flag in Blue Gecko Bluetooth event stack
	gecko_external_signal(POR_EVENT);
	CORE_ATOMIC_IRQ_ENABLE();
}


/** Start TIMER0, with counter value for 80ms
 *
 */
void timer0_start(uint32_t counter_value)
{
	blockSleepMode(EM1);
	TIMER_TopSet(TIMER0, counter_value);
	TIMER_CounterSet(TIMER0, 0x00);
	TIMER_Enable(TIMER0, true);
}
