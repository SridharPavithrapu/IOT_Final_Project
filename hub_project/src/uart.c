/********************************************************************************
* File Name 	  : uart.c
* File Description: This file has the interfaces for UART
* Author		  : Sridhar Pavithrapu
* Date			  : 04/22/2018
* Compiler : arm-none-eabi-gcc
* Linker   : arm-none-eabi-ld
* Debugger : gdb
********************************************************************************/

//***********************************************************************************
// Include files
//***********************************************************************************
#include "uart.h"

void uart_init()
{
#if 0
	LEUART_Init_TypeDef init = LEUART_INIT_DEFAULT;
	init.enable = leuartDisable;
	//init.baudrate = 115200;

	LEUART_Init(LEUART0, &init);

	LEUART0->ROUTEPEN |= USART_ROUTEPEN_RXPEN | USART_ROUTEPEN_TXPEN;
	LEUART0->ROUTELOC0 = (LEUART0->ROUTELOC0 &~(_LEUART_ROUTELOC0_TXLOC_MASK | _LEUART_ROUTELOC0_RXLOC_MASK ))
			                    				 | _LEUART_ROUTELOC0_TXLOC_LOC0
												 | _LEUART_ROUTELOC0_RXLOC_LOC0;

	/* Clear previous RX interrupts */
	LEUART_IntClear(LEUART0, LEUART_IF_RXDATAV);
	NVIC_ClearPendingIRQ(LEUART0_IRQn);

	/* Finally enable it */
	LEUART_Enable(LEUART0, leuartEnable);

	LEUART_Tx(LEUART0,'a');
	LEUART_Tx(LEUART0,1);
	LEUART_Tx(LEUART0,2);
	LEUART_Tx(LEUART0,'a');
	LEUART_Tx(LEUART0,'a');
#endif

#if 1
	USART_InitAsync_TypeDef uartInit = USART_INITASYNC_DEFAULT;

	USART_InitAsync(USART0, &uartInit);



	/* enable IO pins at USART0 location 0*/
	//uart->ROUTEPEN = USART_ROUTEPEN_RXPEN | USART_ROUTEPEN_TXPEN;

	USART0->ROUTEPEN |= USART_ROUTEPEN_RXPEN | USART_ROUTEPEN_TXPEN;
	USART0->ROUTELOC0 = (USART0->ROUTELOC0 &~(_USART_ROUTELOC0_TXLOC_MASK | _USART_ROUTELOC0_RXLOC_MASK ))
		                    				 | _USART_ROUTELOC0_TXLOC_LOC0
											 | USART_ROUTELOC0_RXLOC_LOC0;




	/*Prepare UART Rx and TX interrupts*/
	USART_IntClear(USART0, _USART_IF_MASK);
	USART_IntEnable(USART0, USART_IF_RXDATAV);
	NVIC_ClearPendingIRQ(USART0_RX_IRQn);
	NVIC_ClearPendingIRQ(USART0_TX_IRQn);
//	NVIC_EnableIRQ(USART0_RX_IRQn);
//	NVIC_EnableIRQ(USART0_TX_IRQn);

	/* Enabling UART*/
	USART_Enable(USART0, usartEnable);


#endif

}


void LDMA_IRQHandler(void)
{
	LDMA->IFC = 0x80000001;
}
