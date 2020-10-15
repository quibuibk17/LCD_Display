/*
 * LCD.h
 *
 * Created: 10/15/2020 9:18:44 PM
 *  Author: Admin
 */ 


#ifndef LCD_H_
#define LCD_H_


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_Command_Dir DDRC
#define LCD_Command_Port PORTC
#define LCD_Data_Dir DDRD
#define LCD_Data_Port PORTD

#define RS 0
#define EN 1

void LCD_Init(void);
void LCD_Command(unsigned char);
void LCD_Char(unsigned char);
void LCD_String(char*);
void LCD_String_xy(char, char, char*);



#endif /* LCD_H_ */