/********************************************************************************
* File Name 	  : letimer.h
* File Description: This file has prototype for LETIMER0 initialization
* 					function
* Author		  : Sridhar Pavithrapu
* Date			  : 01/31/2018
********************************************************************************/

/*Include guard */
#ifndef LETIMER_H_
#define LETIMER_H_

//***********************************************************************************
// Include files
//***********************************************************************************
#include "em_core.h"
#include "em_cmu.h"
#include "em_letimer.h"
#include "native_gecko.h"

//***********************************************************************************
// Global variables
//***********************************************************************************

//***********************************************************************************
// function prototypes
//***********************************************************************************

/************************************************************************************
Name: letimer0_init
Description : Initializes the LETIMER0 and loads the appropriate values in the
			  corresponding registers
Inputs: N/A
Returns N/A
************************************************************************************/

void letimer0_init(void);

#endif
