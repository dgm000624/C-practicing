/*
 * int.c
 *
 * Created: 2025-08-25 오전 9:19:52
 *  Author: COMPUTER
 */ 

#include "int.h"
#include "../LCD/LCD.h"
#include "../UART/UART.h"
#include "../Timer/Timer.h"

ISR(INT0_vect)
{
	LCD_Init();
}

ISR(INT1_vect)
{
	if(locked == 1) return;
	USART0_str("\r\nRepeater says it's safe!\r\n");
	Init_time();
	LCD_strout(1, 0, "Press 0 to Init");
	_delay_ms(50);
}

ISR(INT2_vect)
{
	if(locked == 1) return;
	USART0_str("\r\nRepeater says it's strange!\r\n");
	Init_time();
	LCD_strout(1, 0, "Press 0 to Init");
	_delay_ms(50);
}

ISR(INT3_vect)
{
	if(locked == 1) return;
	USART0_str("\r\nRepeater says Emergency!!!!\r\n");
	Init_time();
	LCD_strout(1, 0, "Press 0 to Init");
	_delay_ms(50);
}

void Init_int()		//push button 1 ~ 4번까지 인터럽트 활성화. 5번부터는 E포트 써야함
{
	EICRA = (1 << ISC01 | 1 << ISC00 | 1 << ISC11 | 1 << ISC10 | 1 << ISC21 | 1 << ISC20 | 1 << ISC31 | 1 << ISC30);
	EIMSK = (1 << INT0 | 1 << INT1 | 1 << INT2 | 1 << INT3);
	sei();
}

void Lock_int()
{
	EIMSK &= ~(1 << INT0 | 1 << INT1 | 1 << INT2 | 1 << INT3);
}

char select(int max_sel)
{
	char input;
	
	while (1)
	{
		while (Rflag == 0);
		input = data;
		
		if (input < '1' || input > '0'+max_sel)
		{
			USART0_str("Wrong choice!\r\n");
			Rflag = 0;
			
			continue;
		}
		else
		{
			Rflag = 0;
			return input;
		}
	}

}
