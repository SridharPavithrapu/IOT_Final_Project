/*
 * lcd.h
 *
 *  Created on: Apr 29, 2018
 *      Author: Rishi
 */

#ifndef LCD_H_
#define LCD_H_

void LCD_init(void);
void LCD_clear_and_display(char*);
void LCD_display(char*);
void LCD_passkey_display(uint32_t);


#endif /* LCD_H_ */
