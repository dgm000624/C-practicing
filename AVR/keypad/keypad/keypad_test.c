/*
 * keypad.c
 *
 * Created: 2025-08-21 오전 10:34:37
 * Author : COMPUTER
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "Lcd/LCD.h"

#define ROWS 4	//행(입력)
#define COLS 3	//열(출력)

const unsigned char pads[ROWS][COLS] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8' , '9'}, {'*', '0', '#'}};
	
int temp = 0;
int rows = 0;
int cols = 0;

const unsigned int pass = 1234;

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

int main(void)
{
	
	PortInit();
	LCD_Init();
	
	keypad_Init();
	Byte curr;
	
	
    while (1) 
    {
		LCD_pos(0,0);
		curr = findnumber();
		LCD_CHAR(curr);
	
    }
}

// Byte arr[20] = NULL;
// 
// for (int k = 0; k < sizeof(arr); k++)
// {
// 	LCD_pos(0,k);
// 	LCD_CHAR(arr[k]);
// }

