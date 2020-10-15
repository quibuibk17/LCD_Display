/*
 * 4bit_LCD.c
 *
 * Created: 10/15/2020 9:16:56 PM
 * Author : Admin
 */ 

#include "LCD.h"

int main(void)
{
    LCD_Init();
    LCD_String_xy(1, 5, "Hello!");
    _delay_ms(10);
    LCD_String_xy(2, 5, "Goodbye!");
    while (1) 
    {
    }
}


