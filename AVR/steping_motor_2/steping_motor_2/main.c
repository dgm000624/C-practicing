/*
 * steping_motor_2.c
 *
 * Created: 2025-08-21 오전 10:06:26
 * Author : COMPUTER
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    int i;
	DDRD = 0x0f;
    while (1) 
    {
		for(i=0;i<12;i++){
			PORTD = 0x03;
			_delay_ms(10);
			
			PORTD = 0x09;
			_delay_ms(10);
			
			PORTD = 0x0C;
			_delay_ms(10);
			
			PORTD = 0x06;
			_delay_ms(10);
		}
		_delay_ms(5000);
    }
}

