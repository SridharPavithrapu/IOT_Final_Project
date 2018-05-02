/********************************************************************************
* File Name 	  : cmu.c
* File Description: This file has the initializations for clocks to various
* 					peripherals on the Blue gecko
* Author		  : Sridhar Pavithrapu
* Date			  : 01/31/2018
* Compiler : arm-none-eabi-gcc
* Linker   : arm-none-eabi-ld
* Debugger : gdb
********************************************************************************/

//***********************************************************************************
// Include files
//***********************************************************************************
#include "cmu.h"



//***********************************************************************************
// function definitions
//***********************************************************************************
void cmu_init(void)
{
	uint8_t Prescalar = 1;

	/*Using ULFRCO for EM3 energy mode for LETIMER0*/
	CMU_OscillatorEnable(cmuOsc_ULFRCO, true, true);
	CMU_ClockSelectSet(cmuClock_LFA,cmuSelect_ULFRCO);

	/*Determine the correct prescaler value*/
	uint32_t CurrentFreq = CMU_ClockFreqGet(cmuClock_LFA);
	while((CurrentFreq * TIME_PERIOD) < (LETIMER0_MAX_VAL * Prescalar))
	{
		Prescalar++;
	}

	/*Prescale the clock based on the the above calculated prescaled value*/
	CMU_ClockPrescSet(cmuClock_LETIMER0,Prescalar);
	CMU_ClockEnable(cmuClock_CORELE, true);
	CMU_ClockEnable(cmuClock_LETIMER0, true);

#if 1
	CMU_ClockEnable(cmuClock_HFPER, true);
	CMU_ClockEnable(cmuClock_USART0, true);
	CMU_ClockEnable(cmuClock_GPIO, true);
	CMU_ClockEnable(cmuClock_LDMA,true);
#endif

#if 0
	CMU_ClockEnable(cmuClock_HFPER, true);
	CMU_ClockEnable(cmuClock_GPIO, true);
	CMU_ClockEnable(cmuClock_CORELE, true);
	CMU_ClockSelectSet(cmuClock_LFB, cmuSelect_LFXO);
	CMU_ClockEnable(cmuClock_LEUART0, true);

	CMU_ClockDivSet(cmuClock_LEUART0, cmuClkDiv_1);
#endif
}

