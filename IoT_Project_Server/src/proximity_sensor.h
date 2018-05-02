/*
 * proximity_sensor.h
 *
 *  Created on: Apr 22, 2018
 *      Author: Rishi
 */

#ifndef PROXIMITY_SENSOR_H_
#define PROXIMITY_SENSOR_H_


// Proximity Sensor (VCNL4010) registers
#define PROX_CMD_REG						(0x80)
#define PROX_ID_REG							(0x81)
#define PROX_RATE_OF_PROX_MEASURE_REG		(0x82)
#define PROX_LED_CURR_SETTING_REG			(0x83)
#define PROX_MEASURE_RESULT_HIGH_BYTE_REG	(0x87)
#define PROX_MEASURE_RESULT_LOW_BYTE_REG	(0x88)
#define PROX_INTERRUPT_CTL_REG				(0x89)
#define PROX_LOW_THRESH_HIGH_BYTE_REG		(0x8A)
#define PROX_LOW_THRESH_LOW_BYTE_REG		(0x8B)
#define PROX_HIGH_THRESH_HIGH_BYTE_REG		(0x8C)
#define PROX_HIGH_THRESH_LOW_BYTE_REG		(0x8D)
#define PROX_INTERRUPT_STATUS_REG			(0x8E)


#define PROX_HIGH_BYTE_THRESHOLD					(0x0F)
#define PROX_LOW_BYTE_THRESHOLD						(0xA0)

#define PROXIMITY_SENSOR_EVENT				(0x03)
uint16_t prox_read();
void prox_init();
void prox_ps_init(uint32_t, uint16_t);

#endif /* PROXIMITY_SENSOR_H_ */
