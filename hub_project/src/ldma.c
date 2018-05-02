/********************************************************************************
* File Name 	  : ldma.c
* File Description: This file has the initializations of ldma
* Author		  : Sridhar Pavithrapu
* Date			  : 04/23/2018
* Compiler : arm-none-eabi-gcc
* Linker   : arm-none-eabi-ld
* Debugger : gdb
********************************************************************************/

//***********************************************************************************
// Include files
//***********************************************************************************
#include "ldma.h"

void ldma_init()
{
	LDMA_Init_t ldma_cfg = LDMA_INIT_DEFAULT;
	LDMA_Init(&ldma_cfg);

}
