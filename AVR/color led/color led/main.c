/*
 * color led.c
 *
 * Created: 2025-08-19 오후 1:47:30
 * Author : COMPUTER
 */ 

#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>

unsigned RGB_Table[5][3] = {
	{163, 191, 64},		// Green Yellow
	{255, 69, 0},		// Orange Red
	{34, 139, 34},		// Forest Green
	{135, 206, 235},	// Sky Blue
	{128, 0, 128},		// Purple
};

int main(void)
{
	unsigned char i = 0;
	DDRB = 0xe0;
	ASSR = 0;
	
	TCCR1A = 0xa9;
	TCCR1B = 0x02;
	TCCR1C = 0x00;
   
    while (1) 
    {
		for(i = 0; i < 5; i++){
			OCR1AL = RGB_Table[i][0];
			OCR1BL = RGB_Table[i][1];
			OCR1CL = RGB_Table[i][2];
			_delay_ms(1000);
		}
    }
}

