/********************************************************************************************************************
* File Name 	  : ps.c
* File Description: This file contains the routine declarations for persistent data load and store
* Author		  : Rishi Soni
* Date			  : 03/29/2018
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

#ifndef PS_H_
#define PS_H_

#include "main.h"

uint16_t ps_save_object(uint16_t, void*, uint8_t);
uint16_t ps_load_object(uint16_t, void*, uint8_t);

// Persistent memory map key

#define PS_PROX_HIGH_BYTE_KEY				(0x4001)
#define PS_PROX_LOW_BYTE_KEY				(0x4002)
#define	PS_TEMP_KEY							(0x4003)
#define PS_FLAG_KEY							(0x4004)

#endif /* PS_H_ */
