/*
 * color led.c
 *
 * Created: 2025-08-19 오후 1:47:30
 * Author : COMPUTER
 */


#include "color.h"

unsigned RGB_Table[3][3] = {
	{0,	255	,	0},		//Green
	{255, 255, 0},		//Yellow
	{255, 0, 0}			//Red
};

void Init_color(void)
{
	DDRB |= 0xe0;
	ASSR = 0;
	
	TCCR1A = 0xa9;
	TCCR1B = 0x02;
	TCCR1C = 0x00;
}

void change_color(char color)
{
	int temp = color - '1';

	OCR1A = ~RGB_Table[temp][0];
	OCR1B = ~RGB_Table[temp][1];
	OCR1C = ~RGB_Table[temp][2];

}
