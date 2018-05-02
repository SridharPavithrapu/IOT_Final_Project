/*
 * read_write.c
 *
 *  Created on: Apr 22, 2018
 *      Author: Rishi
 */

#include "main.h"

uint8_t read8(uint8_t reg_addr)
{
	uint8_t temp;
	I2C_TransferSeq_TypeDef seq =
	{
			I2C_SLAVE_ADDR << 1,
			I2C_FLAG_WRITE,
			&reg_addr,
			1
	};
	I2C_TransferReturn_TypeDef ret;
	uint32_t timeout = I2CSPM_TRANSFER_TIMEOUT;

	// LPM: I2C ON
	i2c0_power(true);

	/* Polled write*/
	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress && timeout--)
		ret = I2C_Transfer(I2C0);

	/* Polled read*/
	seq.flags = I2C_FLAG_READ;
	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress && timeout--)
		ret = I2C_Transfer(I2C0);
	temp = seq.buf[0].data[0];

	// LPM: I2C OFF
	i2c0_power(false);
	return temp;
}

uint16_t read16(uint8_t reg_addr)
{
	uint16_t prox;
	I2C_TransferSeq_TypeDef seq =
	{
			I2C_SLAVE_ADDR << 1,
			I2C_FLAG_WRITE,
			&reg_addr,
			1
	};
	I2C_TransferReturn_TypeDef ret;
	uint32_t timeout = I2CSPM_TRANSFER_TIMEOUT;

	// LPM: I2C ON
	i2c0_power(true);

	/* Polled write*/
	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress && timeout--)
		ret = I2C_Transfer(I2C0);

	/* Polled read*/
	seq.flags = I2C_FLAG_READ;
	seq.buf[0].len = 2;
	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress && timeout--)
		ret = I2C_Transfer(I2C0);
	prox = (seq.buf[0].data[0]) << 8;
	prox |= seq.buf[0].data[1];

	// LPM: I2C OFF
	i2c0_power(false);

	return prox;
}

void write8(uint8_t reg_addr, uint8_t data)
{
	uint8_t buf[2] = {reg_addr, data};
	I2C_TransferSeq_TypeDef seq =
	{
			I2C_SLAVE_ADDR << 1,
			I2C_FLAG_WRITE,
			buf,
			2
	};
	I2C_TransferReturn_TypeDef ret;
	uint32_t timeout = I2CSPM_TRANSFER_TIMEOUT;

	// LPM: I2C ON
	i2c0_power(true);

	/* Polled write*/
	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress && timeout--)
		ret = I2C_Transfer(I2C0);

	// LPM: I2C OFF
	i2c0_power(false);
}
