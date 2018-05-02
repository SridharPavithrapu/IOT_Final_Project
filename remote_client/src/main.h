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
#include "em_gpio.h"
#include "em_timer.h"
#include "graphics.h"
#include "native_gecko.h"
#include "infrastructure.h"


#include"lcd.h"
#include "gpio.h"
#include "persistent_mem.h"


#define MAX_SERVER_CONNECTIONS 2
#define FIND_SERVICE	2
#define FIND_CHAR		3
#define ENABLE_NOTIF 	4
#define DATA_MODE		5


/* MITM parameters */
#define BONDING_MITM_PROTECTION     (1)				/* Bit 0  - MITM protection*/
#define BONDING_ENCRYPTION          (0 << 1)		/* Bit 1 - Encryption without Bonding */
#define SECURE_CONNECTION           (1 << 2)		/* Bit 2 - Enable secure connections */
#define NO_BONDING                  (0 << 3)		/* Bit 3  - Bonding request*/

#define BONDING_VAR              (1)
#define NUM_ZERO		(0)
#define NUM_ONE			(1)

#define PRODUCT1_PRODUCT_MEMORY		(0x4000)
#define PRODUCT1_BATTERY_MEMORY		(0x4001)


uint8_t battery_status_received[3];
uint8_t product_count_received[3];

/* UUID and handles for product count */
const uint8 product_serviceUUID[16] = {0xd6, 0x2b, 0xcb, 0x59,
										0x32, 0xe5, 0x97, 0x92,
										0x52, 0x42, 0x53, 0xc9,
										0xa3, 0x38, 0x94, 0x6e}; /* product service UUID - 6e9438a3-c953-4252-9297-e53259cb2bd6 */
const uint8 product_charUUID[16] = {0x20, 0x4e, 0x7c, 0xfa,
										0x26, 0x56, 0x0c, 0x83,
										0x3e, 0x42, 0x8d, 0x7c,
										0x2f, 0x49, 0x55, 0x61}; /* product characteristic UUID - 6155492f-7c8d-423e-830c-5626fa7c4e20 */

static uint32 _product_service_handle;
static uint16 _product_char_handle;


/* UUID and handles for battery status */
const uint8 battery_serviceUUID[16] = {0x7e, 0xbf, 0x4f, 0xed,
										0x60, 0xc6, 0xcb, 0xb7,
										0xc7, 0x4e, 0x2d, 0x37,
										0x78, 0x79, 0x3a, 0x76}; /* battery service UUID - 763a7978-372d-4ec7-b7cb-c660ed4fbf7e */
const uint8 battery_charUUID[16] = {0x39, 0xa9, 0x04, 0x8e,
										0xc5, 0x80, 0x76, 0xb3,
										0x55, 0x46, 0x62, 0x43,
										0x41, 0x5a, 0x54, 0xe2}; /* battery characteristic UUID - e2545a41-4362-4655-b376-80c58e04a939 */

static uint32 _battery_service_handle;
static uint16 _battery_char_handle;

//***********************************************************************************
// function prototypes
//***********************************************************************************
#endif
