/*
 * int.c
 *
 * Created: 2025-08-13 오후 1:26:54
 * Author : COMPUTER
 */ 
#define F_CPU 16000000L

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int idx = 0;
unsigned int Font2[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

ISR(INT3_vect){
	if (idx==9) idx = 0;
	else	idx++;
}

int main(void)
{
	
	
    DDRA = 0xff;		//LED
	DDRD = 0x00;		// push 입력
	DDRB = 0xff;
	
	//EICRA = (ISC01 = 1 | ISC00 = 1);
	//EICRA는 0~3까지 
	EICRA = (1 << ISC31 | 1<<ISC30);
	EIMSK = 1 << INT3;
	
	sei();
	PORTB = 0x07;

	
    while (1) 
    {
		PORTA = ~Font2[idx];
	
		
    }
}

