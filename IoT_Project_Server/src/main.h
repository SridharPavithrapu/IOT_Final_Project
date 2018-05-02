/********************************************************************************************************************
* File Name 	  : main.h
* File Description: This file has macros for time periods for LETIMER, and header files for different parts of the
* 					program. It also contains a macro for the minimum energy mode ("MIN_MODE") for setting the lowest
* 					energy mode available to the LETIMER0
* Author		  : Rishi Soni
* Date			  : 01/29/2018
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

#ifndef MAIN_H_
#define MAIN_H_

#include <adc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
//***********************************************************************************
// defined files
//***********************************************************************************
#include "gpio.h"
#include "cmu.h"
#include "letimer.h"
#include "i2c.h"
#include "sleep.h"
#include "timer.h"
#include "udelay.h"
#include "gatt_db.h"
#include "infrastructure.h"
#include "native_gecko.h"
#include "ps.h"
#include "glib.h"
#include "graphics.h"
#include "lcd.h"
#include "proximity_sensor.h"
#include "i2cspm.h"
#include "read_write.h"
#include "adc.h"
//#include "init_app.h"


#define MIN_MODE		(1)			//lowest energy state available to the LETIMER0

// all values in seconds
#define SLEEP_PERIOD	(2.925)
//#define ON_PERIOD		(0.075)
#define TOTAL_PERIOD	(18)
#define RESET_PERIOD	(0.08)

// Max and Min dBm of radio
#define TX_MAX_dB		(80)		// 8 dBm
#define TX_MIN_dB		(-260)		// -26 dBm

// Advertising values
#define ADV_MIN_INTERVAL	(539.2)
#define ADV_MAX_INTERVAL	(539.2)
#define CHANNELS			(7)
#define ADVERTISING_PERIOD (539.2)

// Connection intervals param
#define CONN_MIN_INTERVAL	(60)
#define CONN_MAX_INTERVAL	(60)
#define SLAVE_LAT			(5)
#define	TIMEOUT				(300)	//3000 ms

// Default threshold as required  by the assignment
#define TEMP_THRESHOLD		(40.0)

/* MITM parameters */
#define BONDING_MITM_PROTECTION     (1)				/* Bit 0  - MITM protection*/
#define BONDING_ENCRYPTION          (0 << 1)		/* Bit 1 - Encryption without Bonding */
#define SECURE_CONNECTION           (1 << 2)		/* Bit 2 - Enable secure connections */
#define NO_BONDING                  (0 << 3)		/* Bit 3  - Bonding request*/


//***********************************************************************************
// global variables
//***********************************************************************************

uint8_t sleep_block_counter[5];
volatile uint16_t schedule_event_program;
volatile uint8_t flag;
volatile uint8_t BLE_connection;

//***********************************************************************************
// function prototypes
//***********************************************************************************


#endif /* MAIN_H_ */
