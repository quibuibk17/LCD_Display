/*
 * LCD.cpp
 *
 * Created: 10/15/2020 12:45:51 AM
 * Author : QuiBui - HCMUT
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_Data_Dir DDRD
#define LCD_Data_Port PORTD
#define LCD_Command_Dir DDRC
#define LCD_Command_Port PORTC

#define RS 0
#define RW 1
#define E 2

void LCD_Send_Char(unsigned char char_data);
void LCD_Send_Command(unsigned char cmd);
void LCD_Send_String(char str[]);

int main(void)
{
    LCD_Data_Dir |= 0xFF; // Cau hinh Port D la Output
	LCD_Command_Dir |= (1 << RS) | (1 << RW) | (1 << E); // Cau hinh Port C 0 1 2 la Output
	
	// Khoi tao LCD
	LCD_Send_Command(0x38); // Mode 8 bit, hien thi 2 dong
	LCD_Send_Command(0x0C); // Bat hien thi, bat con tro
	LCD_Send_Command(0x01);
	
	// Gui chuoi len LCD
	LCD_Send_String("Hello World");
	//LCD_Send_Command(0xC0); // Di chuyen con tro ve dau hang thu 2
	//LCD_Send_String("Goodbye");
	
    while (1) 
    {
    }
}

void LCD_Send_Command(unsigned char cmd)
{
	LCD_Command_Port &= ~(1 << RW);
	LCD_Command_Port &= ~(1 << RS);
	LCD_Data_Port = cmd;
	LCD_Command_Port |= (1 << E);
	_delay_ms(10);
	LCD_Command_Port |= ~(1 << E);
	_delay_ms(30);
}

void LCD_Send_Char(unsigned char char_data)
{
	LCD_Command_Port &= ~(1 << RW);
	LCD_Command_Port |= (1 << RS);
	LCD_Data_Port = char_data;
	LCD_Command_Port |= (1 << E);
	_delay_ms(1);
	LCD_Command_Port &= ~(1 << E);
	_delay_ms(200);
}

void LCD_Send_String(char *str)
{
	int i;
	for(i = 0; str[i] != 0; i++)
	{
		LCD_Send_Char(str[i]);
	}
}