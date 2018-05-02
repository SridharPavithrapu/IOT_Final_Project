/*
 * lcd.c
 *
 *  Created on: Apr 29, 2018
 *      Author: Rishi
 */

#include "lcd.h"
#include <stdint.h>
char buffer[50];

void LCD_init(void)
{
	GRAPHICS_Init();
}

void LCD_clear_and_display(char *str)
{
	GRAPHICS_Clear();
	GRAPHICS_AppendString(str);
	GRAPHICS_Update();
}

void LCD_display(char *str)
{
	GRAPHICS_AppendString(str);
	GRAPHICS_Update();
}

void LCD_passkey_display(uint32_t key)
{
	memset(buffer, 0 , sizeof(buffer));
	sprintf(buffer, "MITM:\nPASSKEY->\n%d", key);
	LCD_clear_and_display(buffer);
}
