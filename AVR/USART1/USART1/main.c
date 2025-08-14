/*
 * USART1.c
 *
 * Created: 2025-08-14 오전 9:28:16
 * Author : COMPUTER
 */ 

#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>

void putch(unsigned char data){
	while(!(UCSR0A & 0x20));	// UCSR0A 버퍼가 비워질때까지 반복. 다 비워지면 ==1이 되며 탈출함
	UDR0 = data;
	//UCSR0A |= 0x20;
	
}
void putstr(unsigned char* str){
	while(*str){
		putch(*str++);
	}
}


int main(void)
{
    unsigned char text[] = "Hello World!!\r\n";
	unsigned char i = 0;
	
	DDRE = 0xfe;
	UCSR0A = 0x00;
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);			// 0x18
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);		// 0x06
	UBRR0H = 0x00;
	UBRR0L = 0x07;
	_delay_ms(1000);
	while(1){
		putstr(text);
		_delay_ms(1000);
	}
	
	while(text[i] !='\0')
	{
		putch((text[i++]));
	}
	return 0;
    
	//while (1) 
    //{
    //}
}

