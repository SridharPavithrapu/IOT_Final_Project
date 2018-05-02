/********************************************************************************************************************
* File Name 	  : gpio.c
* File Description: This file contains the routines for GPIO control
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
#include "main.h"

//***********************************************************************************
// defined files
//***********************************************************************************


//***********************************************************************************
// global variables
//***********************************************************************************
extern bool mitm_enable;


//***********************************************************************************
// function prototypes
//***********************************************************************************


//***********************************************************************************
// functions
//***********************************************************************************

/** Setup the GPIO peripherals for LED, I2C and Si7021 sensor enable
 *
 * Drive Strength can be set to Strong or Weak
 *
 */
void gpio_init(void)
{

	// Set LED ports to be standard output drive with default off (cleared)
//	GPIO_DriveStrengthSet(LED0_port, gpioDriveStrengthStrongAlternateStrong);
//	GPIO_DriveStrengthSet(LED0_port, gpioDriveStrengthWeakAlternateWeak);
//	GPIO_PinModeSet(LED0_port, LED0_pin, gpioModePushPull, LED0_default);

	GPIO_DriveStrengthSet(LED1_port, gpioDriveStrengthStrongAlternateStrong);
//	GPIO_DriveStrengthSet(LED1_port, gpioDriveStrengthWeakAlternateWeak);
	GPIO_PinModeSet(LED1_port, LED1_pin, gpioModePushPull, LED1_default);

//	// Setting I2C GPIO & SENSOR_ENABLE pin modes
	GPIO_PinModeSet(I2C0_PORT, I2C0_SCL, gpioModeWiredAnd, 0);
	GPIO_PinModeSet(I2C0_PORT, I2C0_SDA, gpioModeWiredAnd, 0);
	GPIO_PinModeSet(TEMP_SENSE_EN_PORT, TEMP_SENSE_EN_PIN, gpioModePushPull, 0);

	// Set PD10 as input pin with internal pull-up enabled
	GPIO_PinModeSet(PROX_INTERRUPT_PORT, PROX_INTERRUPT_PIN, gpioModeInputPullFilter, 1);

	// Disable all interrupts
	GPIO_IntDisable(GPIO_IntGet());

	GPIO_PinModeSet(gpioPortF,6,gpioModeInputPullFilter,1);
	GPIO_ExtIntConfig(gpioPortF,6,6,true,true,true);

	// Enable interrupt on GPIO PD10 (Proximity Sensor interrupt pin)
	GPIO_ExtIntConfig(PROX_INTERRUPT_PORT, PROX_INTERRUPT_PIN, PROX_INTERRUPT_PIN, false, true, true);
	// Enable GPIO interrupts in NVIC
	NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
	NVIC_ClearPendingIRQ(GPIO_ODD_IRQn);
	NVIC_EnableIRQ(GPIO_EVEN_IRQn);
	NVIC_EnableIRQ(GPIO_ODD_IRQn);
}

/***************************************************************************//**
 * @brief
 *   GPIO EVEN interrupt handler. Interrupt handler clears all IF even flags
 *
 ******************************************************************************/
void GPIO_EVEN_IRQHandler(void)
{
	// Disable interrupts to avoid nesting
	CORE_ATOMIC_IRQ_DISABLE();

	uint32_t iflags;

	  /* Get all even interrupts. */
	iflags = GPIO_IntGetEnabled() & 0x00005555;

	  /* Clean only even interrupts. */
	GPIO_IntClear(iflags);
	if(mitm_enable == true)
	{
		/* Confirm password */
		mitm_enable = false;
		gecko_cmd_sm_passkey_confirm(BLE_connection, 1);
	}
//	gecko_external_signal(PROXIMITY_SENSOR_EVENT);
	// Re-enable interrupts
	CORE_ATOMIC_IRQ_ENABLE();

}

//void GPIO_ODD_IRQHandler(void)
//{
//	// Disable interrupts to avoid nesting
//	CORE_ATOMIC_IRQ_DISABLE();
//
//	uint32_t iflags;
//
//	  /* Get all even interrupts. */
//	iflags = GPIO_IntGetEnabled() & 0x00005555;
//
//	  /* Clean only even interrupts. */
//	GPIO_IntClear(iflags);
//
//	gecko_external_signal(PROXIMITY_SENSOR_EVENT);
//	// Re-enable interrupts
//	CORE_ATOMIC_IRQ_ENABLE();
//
//}
