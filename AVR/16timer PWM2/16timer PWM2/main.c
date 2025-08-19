/*
 * 16timer PWM2.c
 *
 * Created: 2025-08-19 오후 1:17:27
 * Author : COMPUTER
 */ 

#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{

	DDRB = 0xe0;
	
    while (1) 
    {	
		PORTB = 0xe0;
		_delay_ms(1000);
		
		PORTB = 0x60;
		_delay_ms(1000);
		
		PORTB = 0xa0;
		_delay_ms(1000);
		
		PORTB = 0x20;
		_delay_ms(1000);
		
		PORTB = 0xc0;
		_delay_ms(1000);
		
		PORTB = 0x40;
		_delay_ms(1000);
		
		PORTB = 0x80;
		_delay_ms(1000);
		
		PORTB = 0x00;
		_delay_ms(1000);
		
		
		
    }
}
