/********************************************************************************************************************
* File Name 	  : timer.h
* File Description: This file has routine declarations for TIMER0 initialization and TIMER0 start condition,
* 					for a Blue Gecko C application.
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
#ifndef TIMER_H_
#define TIMER_H_

#include "em_timer.h"



void timer0_init(void);
void timer0_start(uint32_t);


#endif /* TIMER_H_ */
