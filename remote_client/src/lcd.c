/********************************************************************************
* File Name 	  : lcd.c
* File Description: This file has the interfaces for printing on the LCD
* Author		  : Sridhar Pavithrapu
* Date			  : 04/17/2018
* Compiler : arm-none-eabi-gcc
* Linker   : arm-none-eabi-ld
* Debugger : gdb
********************************************************************************/

//***********************************************************************************
// Include files
//***********************************************************************************
#include "lcd.h"

void lcd_initialize(){

	GRAPHICS_Init();
}


void lcd_clear_print(char * input_string){

	GRAPHICS_Clear();
	GRAPHICS_AppendString(input_string);
	GRAPHICS_Update();
}


void lcd_print(char * input_string){

	GRAPHICS_AppendString(input_string);
	GRAPHICS_Update();
}

void lcd_passkey_display(uint32_t passkey){

	char buffer[50];
	memset(buffer,0,sizeof(buffer));
	sprintf(buffer,"MITM:\nPASS_KEY IS:\n%d",passkey);
	lcd_clear_print(buffer);
}
