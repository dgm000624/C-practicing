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
void Serial_Send(unsigned char);	// 문자 보내기 기능
unsigned char Serial_Rece(void);	//에코 기능
void USART0_str(char* str);
void check_pass();

unsigned char data;
unsigned char Rflag;

extern int locked;

char pass[5]; //임시코드



#endif /* UART_H_ */