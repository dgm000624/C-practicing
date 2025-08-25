/*
 * keypad_cal.c
 *
 * Created: 2025-08-21 오후 1:08:44
 * Author : COMPUTER
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Lcd/LCD.h"

#define ROWS 4	//행(입력)
#define COLS 3	//열(출력)

const unsigned char pads[ROWS][COLS] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8' , '9'}, {'*', '0', '#'}};
const unsigned int pass = 1234; 
	
int temp = 0;
int rows = -1;
int cols = -1;

void keypad_Init()
{
	DDRD = 0xF0;		//상위 니블은 출력, 하위 니블은 입력
}

// char keypad_getkey(){
// 	PORTD = 0x10;
// 	if (PIND == 0x01)
// }

int find_ROWS(int temp)
{
	if((temp & 0x01) == 1) return 0;
	else if ((temp & 0x02) == 2) return 1;
	else if ((temp & 0x04) == 4) return 2;
	else if ((temp & 0x08) == 8) return 3;
	else return -1;
}

void reset()
{
	rows = -1;
	cols = -1;
}

Byte findnumber()
{
	for (int i = 0; i<3; i++)
	{
		PORTD |= (1<<(i+4));
		_delay_us(5);
		temp = PIND;
		
		if(((temp&0x01) == 0x01)||((temp&0x02) == 0x02)||((temp&0x04) == 0x04)||((temp&0x08) == 0x08))
		{
			rows = find_ROWS(temp);
			cols = i;
		}
		PORTD &= ~(1 << (i+4));
	}
	
	return pads[rows][cols];
	
}

void inputnums()
{
	static Byte arr[40] = {'\0'};
	
	static int index = 0;
	static int line = 0;
	
	static Byte prev = ' ';
	static Byte curr = ' ';
	
	curr = findnumber();
	reset();
	
	if(prev == curr) return;
	if((curr>=48&&curr<=57) || curr==42 || curr==35)
	{

		arr[index] = curr;
		prev = arr[index];
		index++;
		if(index > 16)
		{
			line = 1;
		}
		_delay_ms(100);
	}
	
	LCD_pos(line, 0);
	
	if (line==1)
	{
		LCD_STR(arr+16);
	}
	else {
		LCD_STR(arr);
	}
	
	
}

int main(void)
{
	
	PortInit();
	LCD_Init();
	
	keypad_Init();
	
	
	
	LCD_pos(0, 0);
	
	while (1)
	{
		
		inputnums();
		
	}
}




