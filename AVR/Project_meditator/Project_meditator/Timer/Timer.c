/*
 * Timer.c
 *
 * Created: 2025-08-25 오전 10:35:16
 *  Author: COMPUTER
 */ 

#include "Timer.h"
#include "../LCD/LCD.h"
#include "../UART/UART.h"

int timer_cnt = 0;
int second = 0;
int timer = 0;
int wait_cnt = 0;

ISR(TIMER3_COMPA_vect)
{
	if(locked == 1) return;
	timer_cnt++;
	
	if (timer_cnt == 2)
	{
		timer_cnt = 0;
		second++;
		wait_cnt++;
	}
	if(second == 15)
	{
		LCD_Init();
		LCD_strout(1,0,"Check Please");
	}
	if(second == 20)
	{	USART0_str("\r\nrepeater no response\r\n");
		second = 0;
	}

	
	
}

void Init_time()
{
	TCNT3H = 0x00;
	TCNT3L = 0x00;
	timer_cnt = 0;
	second = 0;
}

void Init_timer()
{
	ASSR = 0;
	ETIMSK |= 0x10;
	TCCR3A = 0;
	TCCR3B = 0x0d;
	OCR3AH = 0x1c;
	OCR3AL = 0x20;
	TIFR = 0;
	ETIFR = 0;
	sei();
}

void wait(int num)
{
	wait_cnt = 0;
	while(1){
	if(wait_cnt == num)break;
	}
}
