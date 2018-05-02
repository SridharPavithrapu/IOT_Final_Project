/********************************************************************************************************************
* File Name 	  : letimer.h
* File Description: This file has routine declarations for LETIMER initializations, for a Blue Gecko C application.
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
#ifndef LETIMER_H_
#define LETIMER_H_

#include "em_letimer.h"
#define LETIMER_MAX_CNT		(65535)
#define LETIMER_EVENT		(0x01)
#define POR_EVENT			(0x02)

void letimer0_init(void);
void LETIMER_event_handler(void);


#endif /* LETIMER_H_ */
