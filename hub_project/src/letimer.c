/********************************************************************************
* File Name 	  : letimer.c
* File Description: This file has the interrupt handler for LETIMER0 interrupt
* 					the initialization of LETIMER0
* Author		  : Sridhar Pavithrapu
* Date			  : 01/31/2018
* Compiler : arm-none-eabi-gcc
* Linker   : arm-none-eabi-ld
* Debugger : gdb
********************************************************************************/

//***********************************************************************************
// Include files
//***********************************************************************************
#include "letimer.h"

#define TIME_PERIOD 4
#define LETIMER0_COMP0_EVENT (0x01)

//***********************************************************************************
// Functions Definitions
//***********************************************************************************
void letimer0_init(void)
{
	/* First disabling the LETIMER0 */
	LETIMER_Enable(LETIMER0, false);
	
	/* Initializing the parameters for LETIMER0 */
	const LETIMER_Init_TypeDef params =
	{
			false,			  /* Start counting when init completed */
			false,			  /* Counter shall not keep running during debug halt */
			true,			  /* Load COMP0 register into CNT when counter underflows. COMP0 is used as TOP */
			false,			  /* Don't load COMP1 into COMP0 when REP0 reaches 0 */
			0,                /* Idle value 0 for output 0. */
			0,                /* Idle value 0 for output 1. */
			letimerUFOANone,  /* No action on underflow on output 0. */
			letimerUFOANone,  /* No action on underflow on output 1. */
			letimerRepeatFree /* Count until stopped by SW. */
	};
	LETIMER_Init(LETIMER0, &params);

	/* Setting the values for COMP0 */
	uint32_t total_period = CMU_ClockFreqGet(cmuClock_LETIMER0)*TIME_PERIOD ;
	LETIMER_CompareSet(LETIMER0,0,total_period);

	while((LETIMER0->SYNCBUSY));

	/* Clearing and enabling the required interrupts */
	LETIMER_IntClear(LETIMER0,LETIMER_IFC_REP1 | LETIMER_IFC_REP0 | LETIMER_IFC_UF | LETIMER_IFC_COMP1 | LETIMER_IFC_COMP0);
	LETIMER_IntEnable(LETIMER0,LETIMER_IEN_COMP0);
	NVIC_EnableIRQ(LETIMER0_IRQn);


	/* Enabling LETIMER0 */
	LETIMER_Enable(LETIMER0, true);

}

void LETIMER0_IRQHandler(void)
{
	int intFlags;
	/* Disable interrupts to avoid nesting */
	CORE_ATOMIC_IRQ_DISABLE();
	/* Reading the received interrupt */
	intFlags = LETIMER_IntGet(LETIMER0);
	LETIMER_IntClear(LETIMER0, intFlags);
	/* Clearing the interrupt */
	if((intFlags & LETIMER_IF_COMP0))
	{
		gecko_external_signal(LETIMER0_COMP0_EVENT);
	}

	/* Re-enable interrupts */
	CORE_ATOMIC_IRQ_ENABLE();
}
