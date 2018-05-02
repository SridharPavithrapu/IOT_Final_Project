/********************************************************************************
* File Name 	  : gpio.c
* File Description: This file includes the function to initialize the GPIO pin
* 					PortF pin 4 and pin 5 that is connected to LED0 and LED1 and set it to push
* 					pull mode with high drive strength/low drive strength
* Author		  : Sridhar Pavithrapu
* Date			  : 01/31/2018
* Compiler : arm-none-eabi-gcc
* Linker   : arm-none-eabi-ld
* Debugger : gdb
********************************************************************************/


//***********************************************************************************
// Include files
//***********************************************************************************
#include "gpio.h"



/***************************************************************************//**
 * @brief
 *   GPIO EVEN interrupt handler. Interrupt handler clears all IF even flags and
 *   call the dispatcher passing the flags which triggered the interrupt.
 *
 ******************************************************************************/
void GPIO_EVEN_IRQHandler(void)
{
	/* Disable interrupts to avoid nesting */
	CORE_ATOMIC_IRQ_DISABLE();

	uint32_t iflags;

	/* Get all even interrupts. */
	iflags = GPIO_IntGetEnabled() & 0x00005555;

	/* Clean only even interrupts. */
	GPIO_IntClear(iflags);
	if(mitm_server_enable == true)
	{
		mitm_server_enable = false;
		/* Confirm password */
		gecko_cmd_sm_passkey_confirm(_server_conn_handle, 1);
	}
	CORE_ATOMIC_IRQ_ENABLE();
}


void gpio_init(void)
{

	GPIO_PinModeSet(gpioPortF,6,gpioModeInputPullFilter,1);
	GPIO_ExtIntConfig(gpioPortF,6,6,true,true,true);

	NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
	NVIC_EnableIRQ(GPIO_EVEN_IRQn);

}
