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


void lcd_clear_print(char * input_string)
{

	GRAPHICS_Clear();
	GRAPHICS_AppendString(input_string);
	GRAPHICS_Update();
}


void lcd_print(char * input_string)
{

	GRAPHICS_AppendString(input_string);
	GRAPHICS_Update();
}

void lcd_passkey_display(uint8_t server_client, uint32_t passkey)
{
	char buffer[50];
	memset(buffer,0,sizeof(buffer));
	if(server_client == 0)
	{
		sprintf(buffer,"Pass key for\nServer is:\n%d",passkey);
	}
	else
	{
		sprintf(buffer,"Pass key for\nClient is:\n%d",passkey);
	}
	lcd_clear_print(buffer);
}
