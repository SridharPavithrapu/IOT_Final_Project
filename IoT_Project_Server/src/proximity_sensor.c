/*
 * proximity_sensor.c
 *
 *  Created on: Apr 22, 2018
 *      Author: Rishi
 */

#include "main.h"


void prox_init(void)
{
	uint8_t highByte, lowByte;
	// Find if VCNL4010 sensor is connected
	uint8_t sensor_ID = read8((uint8_t)PROX_ID_REG);
	if(sensor_ID == 0x21)
	{
		LCD_display("SENSOR FOUND\n");
	}
	else
	{
		LCD_display("SENSOR NOT FOUND\n");
	}

	// Enable interrupt in sensor
	// Highest IR LED current
	write8(PROX_LED_CURR_SETTING_REG, 20);
	// 1.95 measurements
	write8(PROX_RATE_OF_PROX_MEASURE_REG, 0x00);

	/* Interrupt generation when threshold exceeded
	 * No interrupt for ambient / proximity data ready
	 *  4 counts
	 */
	write8(PROX_INTERRUPT_CTL_REG, 0x42);

	// Store proximity threshold values in persistent memory
	// if not already done in the previous run
//	  static uint8_t ps_flag = 0;
//	  ps_load_object(PS_FLAG_KEY, &ps_flag, sizeof(ps_flag));
//	  if(!ps_flag)
//	  {
//		  ps_flag = 1;
//		  ps_save_object(PS_FLAG_KEY, &ps_flag, sizeof(ps_flag));
//		  prox_ps_init((uint32_t)PROX_HIGH_BYTE_THRESHOLD, (uint16_t)PS_PROX_HIGH_BYTE_KEY);
//		  prox_ps_init((uint32_t)PROX_LOW_BYTE_THRESHOLD, (uint16_t)PS_PROX_LOW_BYTE_KEY);
//	  }
//	  else
//	  {
//		  // Load threshold values from persistent memory
//		  ps_load_object(PS_PROX_HIGH_BYTE_KEY, &highByte, sizeof(highByte));
//		  ps_load_object(PROX_LOW_BYTE_THRESHOLD, &lowByte, sizeof(lowByte));
//	  }
	highByte = 0x0F;
	lowByte = 0xA0;
	/* High threshold value = 4000
	 * Reading exceeds 2100 when object removed near it
	 */
	write8(PROX_HIGH_THRESH_HIGH_BYTE_REG, highByte);
	write8(PROX_HIGH_THRESH_LOW_BYTE_REG, lowByte);

	// Enable continuous mode
	write8(PROX_CMD_REG, 0x03);
	uint8_t int_stat, cmd_stat;
	uint16_t result;
//	while(1)
//	{
		int_stat = read8(PROX_INTERRUPT_STATUS_REG);
		cmd_stat = read8(PROX_CMD_REG);
		result = read16(PROX_MEASURE_RESULT_HIGH_BYTE_REG);
//	}

}

/** Routine to read proximity value from proximity sensor
 * on the I2C bus.
 *
 */
uint16_t prox_read(void)
{
	uint16_t prox;
	uint8_t reg = PROX_ID_REG;
//	i2c0_power(true);

	I2C_TransferSeq_TypeDef seq =
	{
			I2C_SLAVE_ADDR << 1,
			I2C_FLAG_WRITE,
			&reg,
			1
	};
	I2C_TransferReturn_TypeDef ret;
	uint32_t timeout = I2CSPM_TRANSFER_TIMEOUT;
	i2c0_power(true);
	/* Do a polled transfer */
	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress && timeout--)
	{
		ret = I2C_Transfer(I2C0);
	}

	seq.flags = I2C_FLAG_READ;
	/* Do a polled transfer */
	ret = I2C_TransferInit(I2C0, &seq);
	while (ret == i2cTransferInProgress && timeout--)
	{
		ret = I2C_Transfer(I2C0);
	}

	prox = *(seq.buf[0].data);
	i2c0_power(false);
	return prox;
}

/*Function to save threshold values in persistent memory corresponding to key*/
void prox_ps_init(uint32_t threshold, uint16_t key)
{
	if(!(ps_save_object(key, (void*)&threshold, sizeof(threshold))))
	{
		GRAPHICS_AppendString("PS data save SUCCESS\n");
		GRAPHICS_Update();
	}
}


