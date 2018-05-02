/********************************************************************************
* File Name 	  : main.h
* File Description: This file includes the global variables and other included
* 					header files for main.c
* Author		  : Sridhar Pavithrapu
* Date			  : 01/31/2018
********************************************************************************/

/*Include guard */
#ifndef MAIN_H_
#define MAIN_H_

//***********************************************************************************
// Include files
//***********************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "em_letimer.h"
#include "em_emu.h"
#include "em_core.h"
#include "em_cmu.h"
#include "em_i2c.h"
#include <em_usart.h>
#include "em_gpio.h"
#include <em_ldma.h>
#include "em_timer.h"
#include "graphics.h"
#include "native_gecko.h"
#include "infrastructure.h"

#include "cmu.h"
#include "lcd.h"
#include "gpio.h"
#include "persistent_mem.h"
#include "uart.h"
#include "ldma.h"
#include "letimer.h"



#define MAX_SERVER_CONNECTIONS 		2
#define FIND_SERVICE				2
#define FIND_CHAR					3
#define ENABLE_NOTIF 				4
#define DATA_MODE					5


/* MITM parameters */
#define BONDING_MITM_PROTECTION     (1)				/* Bit 0  - MITM protection*/
#define BONDING_ENCRYPTION          (0 << 1)		/* Bit 1 - Encryption without Bonding */
#define SECURE_CONNECTION           (1 << 2)		/* Bit 2 - Enable secure connections */
#define NO_BONDING                  (0 << 3)		/* Bit 3  - Bonding request*/

#define BONDING_VAR              	(1)
#define NUM_ZERO					(0)
#define NUM_ONE						(1)


#define PRODUCT1_PRODUCT_MEMORY		(0x4000)
#define PRODUCT1_BATTERY_MEMORY		(0x4001)
#define PS_FLAG_KEY					(0x4002)




uint8_t battery_status_received[3];
uint8_t product_count_received[3];

/* UUID and handles for product count */
const uint8_t product_serviceUUID[16] = {0x40, 0xa2, 0xca, 0x6e,
										0xc4, 0x80, 0xda, 0xbc,
										0xf9, 0x49, 0x9c, 0xee,
										0x60, 0x31, 0x76, 0x8d}; /* product service UUID - 8d763160-ee9c-49f9-bcda-80c46ecaa240 */
const uint8_t product_charUUID[16] = {0x5a, 0x98, 0x3c, 0x0e,
										0xd5, 0xb4, 0xcc,0x90,
										0x6c, 0x48, 0x2c, 0x0b,
										0xae, 0xf4, 0xd8, 0x11}; /* product characteristic UUID - 11d8f4ae-0b2c-486c-90cc-b4d50e3c985a */

static uint32_t _product_service_handle;
static uint16_t _product_char_handle;


/* UUID and handles for battery status */
const uint8_t battery_serviceUUID[16] = {0xe9, 0x22, 0x16, 0x71,
										0x5b, 0x84, 0xbc, 0xa0,
										0xbb, 0x45, 0xba, 0x97,
										0xe2, 0x0a, 0xdb, 0x2a}; /* battery service UUID - 2adb0ae2-97ba-45bb-a0bc-845b711622e9 */
const uint8_t battery_charUUID[16] = {0x66, 0xe4, 0xbd, 0x36,
									0x71, 0x64, 0x57, 0xae,
									0x8b, 0x43, 0xe6, 0xc6,
									0x2c, 0x8f, 0xf3, 0xf2}; /* battery characteristic UUID - f2f38f2c-c6e6-438b-ae57-647136bde466 */

static uint32_t _battery_service_handle;
static uint16_t _battery_char_handle;

//***********************************************************************************
// function prototypes
//***********************************************************************************
#endif
