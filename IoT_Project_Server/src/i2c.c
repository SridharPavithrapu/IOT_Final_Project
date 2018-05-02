/********************************************************************************************************************
* File Name 	  : i2c.c
* File Description: This file contains the routines for I2C0 initialization and temperature read from Si7021
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
#include "main.h"


/** Initialize I2C0 peripheral
 *
 * Disable timer after running once
 */
void i2c0_init(void)
{
	// Routing I2C0 pins
	I2C0->ROUTEPEN = I2C_ROUTEPEN_SDAPEN | I2C_ROUTEPEN_SCLPEN;
	I2C0->ROUTELOC0 = I2C_ROUTELOC0_SCLLOC_LOC14 | I2C_ROUTELOC0_SDALOC_LOC16;

	/* Initializing the parameters for I2C0 */
	const I2C_Init_TypeDef I2C_PARAMS =
	{
			false,              	/** Enable I2C peripheral when init completed. */
			true,               	/** Set to master (true) or slave (false) mode */
			0,                  	/* I2C reference clock */
			I2C_FREQ_STANDARD_MAX,	/* Set to standard rate  */
			i2cClockHLRStandard		/* Set to use 4:4 low/high duty cycle */
	};

	/* Clearing the interrupts */
	I2C_IntClear(I2C0, 0x0007FFFF);

	I2C_Init(I2C0, &I2C_PARAMS);

}

/** I2C0 LPM routine
 *
// * Unblock from EM1 after LPM sensor switch OFF
 */
void i2c0_power(bool power)
{
//	i2c0_init();
	if(power == true)
	{
		// Setting I2C GPIO pin modes
		GPIO_PinModeSet(I2C0_PORT, I2C0_SCL, gpioModeWiredAnd, 1);
		GPIO_PinModeSet(I2C0_PORT, I2C0_SDA, gpioModeWiredAnd, 1);

		// Toggle I2C SCL 9 times to reset any I2C slave that may require it
		for(int i=0; i < 9; i++)
		{
			GPIO_PinOutClear(I2C0_PORT, I2C0_SCL);
			GPIO_PinOutSet(I2C0_PORT, I2C0_SCL);
		}

		// Exit the bus state
		if(I2C0->STATE & I2C_STATE_BUSY)
		{
			I2C0->CMD = I2C_CMD_ABORT;
		}

		// Enable the I2C peripheral
		I2C_Enable(I2C0, true);
	}
	else if(power == false)
	{
		GPIO_PinModeSet(TEMP_SENSE_EN_PORT, TEMP_SENSE_EN_PIN, gpioModePushPull, 0);
		GPIO_PinModeSet(I2C0_PORT, I2C0_SCL, gpioModeDisabled, 0);
		GPIO_PinModeSet(I2C0_PORT,I2C0_SDA, gpioModeDisabled, 0);
		I2C_Enable(I2C0, false);
	}
}



/** Routine to read temperature from the temperature sensor
 * on the I2C bus.
 *
 * Return the 14-bit value
 */
uint16_t temp_read(void)
{
	uint16_t temp;
	I2C0->TXDATA = (I2C_SLAVE_ADDR << 1)| I2C_WRITE;
	I2C0->CMD = I2C_CMD_START;
	while((I2C0->IF & I2C_IF_ACK) == 0);
	I2C0->IFC = I2C_IFC_ACK;

	//Read temperature
	I2C0->TXDATA = TEMP_MEASURE_REG;
	I2C0->CMD = I2C_CMD_START;
	while((I2C0->IF & I2C_IF_ACK) == 0);
	I2C0->IFC = I2C_IFC_ACK;

	I2C0->TXDATA = (I2C_SLAVE_ADDR << 1)| I2C_READ;
	I2C0->CMD = I2C_CMD_START;
	while((I2C0->IF & I2C_IF_ACK) == 0);
	I2C0->IFC = I2C_IFC_ACK;

	/* Reading data */
	while((I2C0->IF & I2C_IF_RXDATAV) == 0);

	I2C0->CMD = I2C_CMD_ACK;

	temp = I2C0->RXDATA;

	//Clear out bits for the lower byte
	temp = temp << 8;
	temp |= (I2C0->RXDATA) >> 2;
	I2C0->CMD = I2C_CMD_NACK;
	I2C0->CMD = I2C_CMD_STOP;

	return temp;
}


//uint16_t prox_read(void)
//{
//	uint16_t prox;
//	i2c0_power(true);
////	I2C_Reset(I2C0);
////	// Write cmd reg
//	I2C0->TXDATA = (I2C_SLAVE_ADDR << 1)| I2C_WRITE;
//	I2C0->CMD = I2C_CMD_START;
//	while((I2C0->IF & I2C_IF_ACK) == 0);
//	I2C0->IFC = I2C_IFC_ACK;
//
//	I2C0->TXDATA = PROX_CMD_REG;
////	I2C0->CMD = I2C_CMD_START;
//	while((I2C0->IF & I2C_IF_ACK) == 0);
//	I2C0->IFC = I2C_IFC_ACK;
//
//	I2C0->TXDATA = 0x08;		//on-demand proximity measurement
////	I2C0->CMD = I2C_CMD_START;
//	while((I2C0->IF & I2C_IF_ACK) == 0);
//	I2C0->IFC = I2C_IFC_ACK;
//	I2C0->CMD = I2C_CMD_STOP;
//
//	// Read proximity result high byte reg
//	I2C0->TXDATA = (I2C_SLAVE_ADDR << 1)| I2C_WRITE;
//	I2C0->CMD = I2C_CMD_START;
//	while((I2C0->IF & I2C_IF_ACK) == 0);
//	I2C0->IFC = I2C_IFC_ACK;
//
////	I2C0->TXDATA = PROX_CMD_REG;
//	I2C0->TXDATA = PROX_MEASURE_RESULT_HIGH_BYTE_REG;
////	I2C0->CMD = I2C_CMD_START;
//	while((I2C0->IF & I2C_IF_ACK) == 0);
//	I2C0->IFC = I2C_IFC_ACK;
//	I2C0->CMD = I2C_CMD_STOP;
//
//	I2C0->TXDATA = (I2C_SLAVE_ADDR << 1)| I2C_READ;
//	I2C0->CMD = I2C_CMD_START;
//	while((I2C0->IF & I2C_IF_ACK) == 0);
//	I2C0->IFC = I2C_IFC_ACK;
//
//	/* Reading data */
//	while((I2C0->IF & I2C_IF_RXDATAV) == 0);
//	I2C0->CMD = I2C_CMD_ACK;
//	prox = I2C0->RXDATA << 8;
//	I2C0->CMD = I2C_CMD_NACK;
//	I2C0->CMD = I2C_CMD_STOP;
//
	// Read proximity result low byte reg
//		I2C0->TXDATA = (I2C_SLAVE_ADDR << 1)| I2C_WRITE;
//		I2C0->CMD = I2C_CMD_START;
//		while((I2C0->IF & I2C_IF_ACK) == 0);
//		I2C0->IFC = I2C_IFC_ACK;
//
//	//	I2C0->TXDATA = PROX_CMD_REG;
//		I2C0->TXDATA = PROX_MEASURE_RESULT_LOW_BYTE_REG;
//	//	I2C0->CMD = I2C_CMD_START;
//		while((I2C0->IF & I2C_IF_ACK) == 0);
//		I2C0->IFC = I2C_IFC_ACK;
//		I2C0->CMD = I2C_CMD_STOP;

//	I2C0->TXDATA = (I2C_SLAVE_ADDR << 1)| I2C_READ;
//	I2C0->CMD = I2C_CMD_START;
//	while((I2C0->IF & I2C_IF_ACK) == 0);
//	I2C0->IFC = I2C_IFC_ACK;
//
//	/* Reading data */
//	while((I2C0->IF & I2C_IF_RXDATAV) == 0);
//	I2C0->CMD = I2C_CMD_ACK;
//	prox |= I2C0->RXDATA;
//	I2C0->CMD = I2C_CMD_NACK;
//	I2C0->CMD = I2C_CMD_STOP;
//
//	i2c0_power(false);
//	return prox;
//}




/** Setup the I2C0 IRQ handler
 *
 *  ***Not used in the current application***
 */
void I2C0_IRQHandler(void)
{
	// RXFULL interrupt
	if(I2C0->IF & (1<<17))
	{
		//Disable the RXFULL interrupt
		I2C0->IFC |= I2C_IFC_RXFULL;
	}

}
