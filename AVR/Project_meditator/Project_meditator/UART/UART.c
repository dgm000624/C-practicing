/*
 * UART.c
 *
 * Created: 2025-08-22 오후 12:14:29
 *  Author: COMPUTER
 */

#include "UART.h"

char temp_name[20]; 
char backmenu;

int locked = 1;

void Init_USART(void)		//USART 초기 세팅
{
	DDRE = 0x00;
	UCSR0A = 0x00;
	UCSR0B = 0x98;
	UCSR0C = 0x06;
	UBRR0H = 0x00;
	UBRR0L = 0x07;
}

void Serial_Send(unsigned char t)	// 문자 1개 보내기(char)
{

	while (1) { if ((UCSR0A & 0x20) != 0) break; }
	UDR0 = t;
	UCSR0A = UCSR0A | 0x20;
}

ISR(USART0_RX_vect)	//수신 인터럽트 발생시 실행.
{
	data = UDR0;
	UCSR0A |= 0x80;

	Rflag = 1;
	_delay_ms(5);
}

void USART0_str(char* str)	//문자열 보내기
{
	while (*str) { Serial_Send(*str++); }

}

unsigned char Serial_Rece(void)	//문자 받기
{
	unsigned char data;
	while (1) {
		if ((UCSR0A & 0x80) != 0)break;
	}
	data = UDR0;
	UCSR0A |= 0x80;
	return data;
}

void check_pass()		//비밀번호 세팅용 함수.
{
	clear_terminal();
	USART0_str("\r\n\r\nEnter your pass\r\n");
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

void Init_buff()
{
	while (UCSR0A & (1 << RXC0)) {
    (void)UDR0;  // 수신 데이터 무시하고 읽기
	}
	return;
}

void receive_text()
{
	int i = 0;
	while (1) {
		
		if(i>=19){USART0_str("it's too long!!!\r\n"); return;}
		
		if (Rflag == 0) continue;
		char command = data;
		Rflag = 0;
		if (command == '\r') {temp_name[i] = '\0'; break;}
		
		temp_name[i]=command;
		i++;
	}
}

void reset_text()
{
	for(int i = 0; i < 20; i++)
	{
		temp_name[i] = '\0';
	}
}

void clear_terminal() {
	Serial_Send(0x1B);    // ESC 문자 전송
	USART0_str("[2J");    // 화면 클리어
	Serial_Send(0x1B);    // ESC 문자 전송
	USART0_str("[H");     // 커서를 0,0으로
	USART0_str("\r\n");
}