/********************************************************************************************************************
* File Name 	  : sleep.h
* File Description: This file has routine declarations needed for sleeping in different energy modes, for a Blue Gecko C application.
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

#ifndef SLEEP_H_
#define SLEEP_H_

#include "em_emu.h"
#include "em_core.h"

// Enum defining different Blue Gecko states
enum sleepstate_enum
{
	EM0 = 0,
	EM1 = 1,
	EM2 = 2,
	EM3 = 3,
	EM4 = 4
};

// Sleep Routine declarations
void sleep(void);
void blockSleepMode(enum sleepstate_enum);
void unblockSleepMode(enum sleepstate_enum);


#endif /* SLEEP_H_ */
