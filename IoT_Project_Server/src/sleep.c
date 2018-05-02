/********************************************************************************************************************
* File Name 	  : sleep.c
* File Description: This file has routines needed for sleeping in different energy modes, for a Blue Gecko C application.
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

/** Sleep routine to sleep in different modes
 *
 *	CPU and other peripherals sleep when their corresponding block counter is incremented
 */
void sleep(void)
{
	if(sleep_block_counter[0] > 0)
	{
		return;
	}
	else if(sleep_block_counter[1] > 0)
	{
		EMU_EnterEM1();
	}
	else if(sleep_block_counter[2] > 0)
	{
		EMU_EnterEM2(true);
	}
	else if(sleep_block_counter[3] > 0)
	{
		EMU_EnterEM3(true);
	}
	else
	{
		EMU_EnterEM4();
	}
	return;
}


/** Block the microcontroller from sleeping below a certain mode
 *  This will block sleep() from entering an energy mode below the one given.
 *  --To be called by peripheral HAL's --
 *
 *  After the peripheral is finished with the operation, it should call unblock with the same state
 */
void blockSleepMode(enum sleepstate_enum minimumMode)
{
	CORE_ATOMIC_IRQ_DISABLE();
	sleep_block_counter[minimumMode]++;
	CORE_ATOMIC_IRQ_ENABLE();
}

/** Unlock the microcontroller from sleeping below a certain mode
 *  This will unblock sleep() from entering an energy mode below the one given.
 *  --To be called by peripheral HAL's --
 *
 *  This should be called after all transactions on a peripheral are done
 */
void unblockSleepMode(enum sleepstate_enum minimumMode)
{
	CORE_ATOMIC_IRQ_DISABLE();
	if(sleep_block_counter[minimumMode] > 0)
	{
		sleep_block_counter[minimumMode]--;
	}
	CORE_ATOMIC_IRQ_ENABLE();
}
