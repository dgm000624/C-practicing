/*
 * Led.c
 *
 * Created: 2025-08-11 오후 2:28:22
 * Author : COMPUTER
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRF = 0xFF;			//DDRE(방향설정 레지스트: 1 출력, 0 입력) =  1111 1111
    while (1) 
    {
		/*
		PORTF = 0xAA;
		_delay_ms(500);
		PORTF = 0x00;
		_delay_ms(500);
		*/
		
		PORTF = 0x05;
		_delay_ms(100);
		PORTF = 0x00;
		_delay_ms(100);
		
		PORTF = 0x0A;
		_delay_ms(100);
		PORTF = 0x00;
		_delay_ms(100);
		
		PORTF = 0x50;
		_delay_ms(100);
		PORTF = 0x00;
		_delay_ms(100);
		
		PORTF = 0xA0;
		_delay_ms(800);
		PORTF = 0x00;
		_delay_ms(800);
		
    }
}

