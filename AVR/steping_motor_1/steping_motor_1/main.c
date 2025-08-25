/*
 * steping_motor_1.c
 *
 * Created: 2025-08-21 오전 9:41:24
 * Author : COMPUTER
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = 0x00;
	DDRD |= 0x0f;
	DDRA = 0x0c;
	
	
	
	PORTD = 0x00;
    while (1) 
    {
		PORTD = 0x01;
		_delay_ms(10);
		PORTD = 0x02;
		_delay_ms(10);
		PORTD = 0x04;
		_delay_ms(10);
		PORTD = 0x08;
		_delay_ms(10);
		
		int temp = PINA;
		if(temp==0x01)
		{
			PORTD = 0x08;
			_delay_ms(10);
			PORTD = 0x04;
			_delay_ms(10);
			PORTD = 0x02;
			_delay_ms(10);
			PORTD = 0x01;
			_delay_ms(10);
		}
		else if(temp==0x02)
		{
			{
				PORTD &= 0;
			}
		}
		
    }
}

