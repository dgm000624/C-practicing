/*
 * USART2.c
 *
 * Created: 2025-08-14 오전 10:34:04
 * Author : COMPUTER
 */ 

#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

void Init_USART()
{
	DDRE = 0xfe;
	UCSR0A = 0x00;
	UCSR0B = (1 << RXEN0)| (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0H = 0x00;
	UBRR0L = 0x07;
}

void USART0_tx(unsigned char data)		//송신
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = data;
}

unsigned char USART0_rx()				//수신
{
	while(!(UCSR0A & (1 << RXC0)));
	return UDR0;
}
void usart0_init()
{
	
}

void USART0_char(char data)
{
	while(!(UCSR0A&0x20));
	UDR0=data;
}


void USART0_str(unsigned char* str)
{
	while(*str) {USART0_tx(*str++);}
	
}

void led(int num)
{
	PORTC = 0x00;
	if(num&128) PORTC |= 0x80;
	if(num&64) PORTC |= 0x40;
	if(num&32) PORTC |= 0x20;
	if(num&16) PORTC |= 0x10;
	if(num&8) PORTC |= 0x08;
	if(num&4) PORTC |= 0x04;
	if(num&2) PORTC |= 0x02;
	if(num&1) PORTC |= 0x01;
}



int main(void)
{
	int num = 0;
	DDRC = 0xff;
	unsigned char data;
	int sum = 0;
	//unsigned char str[] = "Hello World!!\r\n";
	Init_USART();
	
	while(1){

		
		
		while(1)
		{
			data = USART0_rx();
			
			if (data == '/') 
			{
				led(sum);
				sum = 0;
				break;
			}
			num = data-'0';
			sum = sum*10 + num;
		}
		
			
			
	}
}

