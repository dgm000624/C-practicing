/*
 * UART.h
 *
 * Created: 2025-08-22 오후 12:14:42
 *  Author: COMPUTER
 */


#ifndef UART_H_
#define UART_H_


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

void Init_USART(void);				// 초기화
void Serial_Send(unsigned char);	// 1문자 보내기 기능
unsigned char Serial_Rece(void);	// 에코 기능
void USART0_str(char* str);			// 문자열 보내기 기능
void check_pass();					// 비밀번호 세팅하기
void Init_buff();					// 인터럽트 비우기
void receive_text();				// 텍스트받아서 name[]에 저장하기
void reset_text();					// name[]을 '\0'으로 초기화
void clear_terminal();

unsigned char data;
unsigned char Rflag;
char temp_name[20]; 

extern int locked;

char pass[5]; //임시코드



#endif /* UART_H_ */