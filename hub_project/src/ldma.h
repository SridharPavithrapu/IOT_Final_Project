/********************************************************************************
* File Name 	  : ldma.h
* File Description: This file has prototype for ldma.c functions
* Author		  : Sridhar Pavithrapu
* Date			  : 01/31/2018
********************************************************************************/

/*Include guard */
#ifndef LDMA_H_
#define LDMA_H_

#include <em_ldma.h>

void ldma_init();
void LDMA_IRQHandler(void);

#endif
