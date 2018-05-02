/********************************************************************************
* File Name 	  : cmu.h
* File Description: This file has prototype for clock initialization
* 					function
* Author		  : Sridhar Pavithrapu
* Date			  : 01/31/2018
********************************************************************************/

/*Include guard */
#ifndef CMU_H_
#define CMU_H_

//***********************************************************************************
// Include files
//***********************************************************************************
#include "em_cmu.h"



//***********************************************************************************
// global variables
//***********************************************************************************
/*Define the maximum count for the 16 bit LETIMER0*/
#define LETIMER0_MAX_VAL (65536)
/* Define the total time period */
#define TIME_PERIOD 4

//***********************************************************************************
// function prototypes
//***********************************************************************************

/************************************************************************************
Name: cmu_init
Description : This function initializes the various clocks for the peripherals on the
			  gecko
Inputs: N/A
Returns N/A
************************************************************************************/
void cmu_init(void);

#endif
