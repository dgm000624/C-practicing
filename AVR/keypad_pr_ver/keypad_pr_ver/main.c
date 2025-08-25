/*
 * keypad_pr_ver.c
 *
 * Created: 2025-08-21 오후 3:32:58
 * Author : COMPUTER
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

char keypad_getkey(){
	PORTD = 0x10;
	_delay_us(4);
	if((PIND&0x01)==0x01) return '1';
	if((PIND&0x02)==0x02) return '4';
	if((PIND&0x04)==0x04) return '7';
	if((PIND&0x08)==0x08) return '*';
	
	PORTD = 0x20;
	_delay_us(4);
	if((PIND&0x01)==0x01) return '2';
	if((PIND&0x02)==0x02) return '5';
	if((PIND&0x04)==0x04) return '8';
	if((PIND&0x08)==0x08) return '0';
	
	PORTD = 0x40;
	_delay_us(4);
	if((PIND&0x01)==0x01) return '3';
	if((PIND&0x02)==0x02) return '6';
	if((PIND&0x04)==0x04) return '9';
	if((PIND&0x08)==0x08) return '#';
	
	return 0;
}