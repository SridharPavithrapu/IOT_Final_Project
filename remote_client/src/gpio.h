/********************************************************************************
* File Name 	  : gpio.h
* File Description: This file includes the definition of LED0 and GPIO function
* 					prototypes
* Author		  : Sridhar Pavithrapu
* Date			  : 01/31/2018
********************************************************************************/

/*Include guard */
#ifndef GPIO_H_
#define GPIO_H_

//***********************************************************************************
// Include files
//***********************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "em_core.h"
#include "em_gpio.h"
#include "native_gecko.h"


extern uint8_t _server_conn_handle;

extern bool mitm_server_enable;


//***********************************************************************************
// function prototypes
//***********************************************************************************

/************************************************************************************
Name: gpio_init
Description : Initializes GPIO pins as specified in the definition
Inputs: N/A
Returns N/A
************************************************************************************/

void gpio_init(void);
void GPIO_EVEN_IRQHandler(void);

#endif
