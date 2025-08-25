/*
 * UART.c
 *
 * Created: 2025-08-22 오후 12:14:29
 *  Author: COMPUTER
 */

#include "UART.h"

int locked = 0;

void Init_USART(void)
{
	DDRE = 0x70;
	UCSR0A = 0x00;
	UCSR0B = 0x98;
	UCSR0C = 0x06;
	UBRR0H = 0x00;
	UBRR0L = 0x07;
}

void Serial_Send(unsigned char t)
{

	while (1) { if ((UCSR0A & 0x20) != 0) break; }
	UDR0 = t;
	UCSR0A = UCSR0A | 0x20;
}

ISR(USART0_RX_vect)
{
	data = UDR0;
	UCSR0A |= 0x80;

	if (data == 127)
	{
		USART0_str("\033[2J\033[H");
		Rflag = 0;
		return;
	}

	Rflag = 1;
	_delay_ms(5);
}

void USART0_str(char* str)
{
	while (*str) { Serial_Send(*str++); }

}

unsigned char Serial_Rece(void)
{
	unsigned char data;
	while (1) {
		if ((UCSR0A & 0x80) != 0)break;
	}
	data = UDR0;
	UCSR0A |= 0x80;
	return data;
}

void check_pass()
{
	USART0_str("\033[2J\033[H");
	USART0_str("Enter your pass\r\n");
	for (int i = 0; i < 4; i++)
	{
		while (1) {
			if (Rflag == 0) continue;
			if (data >= '0' && data <= '9') { pass[i] = data; Rflag = 0; break; }
			else { Rflag = 0; USART0_str("\t input only number \r\n"); }

		}
	}
	pass[4] = '\0';
	USART0_str("\r\nset\t");
	USART0_str(pass);
	USART0_str("\r\n");

}