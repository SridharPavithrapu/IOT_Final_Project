/********************************************************************************
* File Name 	  : persistent_mem.h
* File Description: This file has prototype for clock initialization
* 					function
* Author		  : Sridhar Pavithrapu
* Date			  : 01/31/2018
********************************************************************************/

/*Include guard */
#ifndef PERSISTENT_MEM_H_
#define PERSISTENT_MEM_H_


#include <stdint.h>
#include <stdbool.h>
#include "native_gecko.h"
#include "infrastructure.h"

//***********************************************************************************
// function prototypes
//***********************************************************************************

/************************************************************************************
Name: ps_save_object
Description : This function initializes LCD module.
Inputs: key: persistent memory key
		pValue: value to be stored
		size: size of the data
Returns Success or Failure
************************************************************************************/
uint16_t ps_save_object(uint16_t key, void *pValue, uint8_t size);

//***********************************************************************************
// function prototypes
//***********************************************************************************

/************************************************************************************
Name: ps_load_object
Description : This function load the data from the persistent memory.
Inputs: key: persistent memory key
		pValue: value to be stored
		size: size of the data
Returns value read from persitent memory
************************************************************************************/
uint16_t ps_load_object(uint16_t key, void *pValue, uint8_t size);

#endif
