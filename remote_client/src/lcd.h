/********************************************************************************
* File Name 	  : lcd.h
* File Description: This file has prototype for printing strings on LCD
* Author		  : Sridhar Pavithrapu
* Date			  : 04/17/2018
********************************************************************************/

/*Include guard */
#ifndef LCD_H_
#define LCD_H_

#include <stdint.h>

//***********************************************************************************
// function prototypes
//***********************************************************************************

/************************************************************************************
Name: lcd_initialize
Description : This function initializes LCD module.
Inputs: N/A
Returns N/A
************************************************************************************/
void lcd_initialize();

/************************************************************************************
Name: lcd_clear_print
Description : This function is used to clear and print the input string on LCD
Inputs: N/A
Returns N/A
************************************************************************************/
void lcd_clear_print(char * input_string);

/************************************************************************************
Name: lcd_print
Description : This function is used to print the input string on LCD
Inputs: input_string input string to be printed
Returns N/A
************************************************************************************/
void lcd_print(char * input_string);

/************************************************************************************
Name: lcd_passkey_display
Description : This function print the passkey on the LCD
Inputs: passkey: passkey generated using MITM operation
Returns N/A
************************************************************************************/
void lcd_passkey_display(uint32_t passkey);

#endif
