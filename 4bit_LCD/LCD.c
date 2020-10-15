/*
 * LCD.c
 *
 * Created: 10/15/2020 9:19:21 PM
 *  Author: Admin
 */ 

#include "LCD.h"

void LCD_Init(void)
{
	LCD_Command_Dir |= (1 << RS) | (1 << EN);
	LCD_Data_Dir |= 0xF0;
	_delay_ms(2);
	LCD_Command(0x01); //Xoa toan man hinh
	LCD_Command(0x02); //Di chuyen con tro den dau man hinh
	LCD_Command(0x28); //Giao tiep 4 bit
	LCD_Command(0x06); //Di chuyen con tro den vi tri ke tiep moi khi xuat ra LCD 1 ki tu
	LCD_Command(0x0C); //Bat hien thi va tat con tro
	LCD_Command(0x80); // Di chuyen con tro ve dau dong 1
}

void LCD_Command(unsigned char cmd)
{
	LCD_Data_Port = (LCD_Data_Port & 0x0F) | (cmd & 0xF0);
	LCD_Command_Port &= ~(1 << RS);
	LCD_Command_Port |= (1 << EN);
	_delay_ms(2);
	LCD_Command_Port &= ~(1 << EN);
	_delay_ms(2);
	
	LCD_Data_Port = (LCD_Data_Port & 0x0F) | (cmd << 4);
	LCD_Command_Port |= (1 << EN);
	_delay_ms(2);
	LCD_Command_Port &= ~(1 << EN);
	_delay_ms(2);
}

void LCD_Char(unsigned char data)
{
	LCD_Data_Port = (LCD_Data_Port & 0x0F) | (data & 0xF0);
	LCD_Command_Port |= (1 << RS);
	LCD_Command_Port |= (1 << EN);
	_delay_ms(2);
	LCD_Command_Port &= ~(1 << EN);
	_delay_ms(2);
	
	LCD_Data_Port = (LCD_Data_Port & 0x0F) | (data << 4);
	LCD_Command_Port |= (1 << EN);
	_delay_ms(2);
	LCD_Command_Port &= ~(1 << EN);
	_delay_ms(2);
}

void LCD_String(char *str)
{
	int i;
	for(i = 0; str[i] != 0; i++)
	{
		LCD_Char(str[i]);
		_delay_ms(2);
	}
}

void LCD_String_xy(char row, char col, char *str)
{
	if ((row == 1) && (col < 16))
	{
		LCD_Command(0x80 | (col & 0x0F));
	}
	else if ((row == 2) && (col < 16))
	{
		LCD_Command(0xC0 | (col & 0x0F));
	}
	LCD_String(str);
}