/*
 * LCD.c
 *
 * Created: 2025-08-20 오후 1:16:08
 *  Author: COMPUTER
 */

#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"
#include <string.h>

void PortInit(void)
{
	DDRC = 0xFF;	//DDRC로
	DDRB = 0x07;	//DDRB로		RS RW 는 PORTD에

}

void LCD_Data(Byte ch)
{
	LCD_CTRL |= (1 << LCD_RS);
	LCD_CTRL &= ~(1 << LCD_RW);
	LCD_CTRL |= (1 << LCD_EN);
	_delay_us(50);
	LCD_WDATA = ch;
	_delay_us(50);
	LCD_CTRL &= ~(1 << LCD_EN);
}

void LCD_Comm(Byte ch)
{
	LCD_CTRL &= ~(1 << LCD_RS);
	LCD_CTRL &= ~(1 << LCD_RW);
	LCD_CTRL |= (1 << LCD_EN);
	_delay_us(50);
	LCD_WINST = ch;
	_delay_us(50);
	LCD_CTRL &= ~(1 << LCD_EN);
}

void LCD_CHAR(Byte c)
{

	LCD_Data(c);
	_delay_ms(1);
}

void LCD_STR(Byte* str)
{
	while (*str != 0)
	{
		LCD_CHAR(*str);
		str++;
	}
}

void LCD_pos(unsigned char col, unsigned char row)
{

	LCD_Comm(0x80 | (row + col * 0x40));
}

void LCD_Clear(void)
{
	LCD_Comm(0x01);
	_delay_ms(4);
}

void LCD_Init(void)
{
	LCD_Comm(0x38);
	_delay_ms(2);
	LCD_Comm(0x38);
	_delay_ms(2);
	LCD_Comm(0x38);
	_delay_ms(2);
	LCD_Comm(0x0e);
	_delay_ms(2);
	LCD_Comm(0x06);
	_delay_ms(2);
	LCD_Clear();
}

void LCD_strout(int line, int location, char* message)
{
	LCD_pos(line, location);
	LCD_STR((Byte*)message);
}

void LCD_charout(int line, int location, Byte message)
{
	LCD_pos(line, location);
	LCD_CHAR(message);
}

