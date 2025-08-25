/*
 * AD_convert_minifan.c
 *
 * Created: 2025-08-21 오전 9:20:54
 * Author : COMPUTER
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA = 0x01;
	
   
    while (1) 
    {
		PORTA = 0x01;
		_delay_ms(4000);
		PORTA = 0x00;
		_delay_ms(4000);
		
    }
}

