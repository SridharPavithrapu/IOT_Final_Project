/********************************************************************************************************************
* File Name 	  : cmu.c
* File Description: This file demonstrates the routines needed for setting up the CMU for a Blue Gecko C application.
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


//***********************************************************************************
// Include files
//***********************************************************************************
#include "main.h"

//***********************************************************************************
// defined files
//***********************************************************************************


//***********************************************************************************
// global variables
//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************

/** Setup the clock for the microcontroller, with automatically calculating the
 * prescaling value.
 *
 * Checks the minimum energy state, defined as a macro in "main.h". If below
 * EM3, LFXO is used as clock source. For EM3, ULFRCO used as clock source.
 *
 * Gets the selected clock frequency value through CMU_ClockFreqGet(). A looping mechanism
 * is used to automatically find out the prescaling value, if required, based on the total
 * time period, which is defined as macro in "main.h". This value is used to set the prescaling
 * value for the LETIMER0 in this assignment. Same mechanism can be used for other peripherals
 * as well (extendable)
 *
 *  After prescaler is set, LETIMER0 clock is enabled
 */
void cmu_init(void)
{
	uint8_t prescalar = 1;
	uint32_t clockValue;
	if(MIN_MODE <= 2)
	{
		CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
		CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
	}
	else
	{
		CMU_OscillatorEnable(cmuOsc_ULFRCO, true, true);
		CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_ULFRCO);
	}

	// Calculate the prescalar value
	clockValue = CMU_ClockFreqGet(cmuClock_LFA);
	while(1)
	{
		if(clockValue * TOTAL_PERIOD < LETIMER_MAX_CNT * prescalar)
			break;
		else
			prescalar++;
	}
	CMU_ClockPrescSet(cmuClock_LETIMER0, prescalar);

	// Enable clock for LETIMER0
	CMU_ClockEnable(cmuClock_CORELE, true);
	CMU_ClockEnable(cmuClock_LETIMER0, true);

	// Enable clock for I2C0
//	CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
	CMU_ClockEnable(cmuClock_HFPER, true);
	CMU_ClockEnable(cmuClock_I2C0, true);

	// Enable clock for TIMER0
	CMU_ClockEnable(cmuClock_TIMER0, true);

	// Enable GPIO clock
//	CMU_ClockEnable(cmuClock_GPIO, true);

	/* Enable ADC Clock */
	CMU_ClockEnable(cmuClock_ADC0, true);

}


