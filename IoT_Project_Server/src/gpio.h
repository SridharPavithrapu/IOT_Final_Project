/********************************************************************************************************************
* File Name 	  : gpio.h
* File Description: This file has routine declarations GPIO initialization and the pin and port numbers
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

//***********************************************************************************
// Include files
//***********************************************************************************

#ifndef GPIO_H_
#define GPIO_H_

#include "em_gpio.h"

//***********************************************************************************
// defined files
//***********************************************************************************

// LED0 pin and port
#define	LED0_port			(gpioPortF)
#define LED0_pin			(4)
#define LED0_default		false 	// off

// LED1 pin and port
#define LED1_port			(gpioPortF)
#define LED1_pin			(5)
#define LED1_default		false	// off

// Temperature sensor pin and port
#define TEMP_SENSE_EN_PORT	(gpioPortD)
#define TEMP_SENSE_EN_PIN	(9)

// I2C0 pin and port
#define I2C0_PORT			(gpioPortC)
#define I2C0_SDA			(11)
#define I2C0_SCL			(10)

// Expansion board pin and port
#define PROX_INTERRUPT_PORT	(gpioPortD)
#define PROX_INTERRUPT_PIN	(10)	// Expansion pin = 7

//***********************************************************************************
// global variables
//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************
void gpio_init(void);



#endif /* GPIO_H_ */
