/********************************************************************************************************************
* File Name 	  : gpio.h
* File Description: This file has routine declarations for I2C initialization, temperature read, and LPM
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

#ifndef I2C_H_
#define I2C_H_

#include "em_i2c.h"

#define I2C_SLAVE_ADDR		(0x13)
#define I2C_WRITE			(0x00)
#define I2C_READ			(0x01)
#define TEMP_MEASURE_REG	(0xE3)


#define POWER_ON_RESET_TIME (0x0BB8)
//#define POWER_ON_RESET_TIME (0x0BBB)

void i2c0_init(void);
uint16_t temp_read(void);
void i2c0_power(bool);



#endif /* I2C_H_ */
