/*
 * Project_meditator.c
 *
 * Created: 2025-08-22 오전 9:20:52
 * Author : COMPUTER
 */

 /*
  * USART2.c
  *
  * Created: 2025-08-14 오전 10:34:04
  * Author : COMPUTER
  */

#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include "modules/keypad.h"
#include "UART/UART.h"
#include "LCD/LCD.h"
#include "color_led/color.h"
#include "interrupt/int.h"
#include "Timer/Timer.h"




int main(void)
{
	DDRD = 0x00;

	PortInit();
	LCD_Init();
	locked = 1;
	keypad_Init();
	Init_timer();
	Rflag = 0;

	Init_int();
	Init_USART();

	for (int i = 0; i < 5; i++) {
		Serial_Send('=');
		_delay_ms(500);
	}
	USART0_str("\r\n");
	check_pass();

	USART0_str("Enter password in repeater\r\n");

	while (1) {
		if (cp_pass(pass) == 1) { USART0_str("Correct pass!"); LCD_strout(1, 0, "ACCESS"); locked = 0; break; }
		else { USART0_str("Wrong pass! retry\r\n"); LCD_strout(1, 0, "RETRY"); }
	}



	while (1)
	{
		char choiced = '0';
		USART0_str("\b\r\n\r\nWhat you want?\r\n1. Send Text 2. Send Light 3. Clear interface \r\n");
		choiced = select(3);
		if (locked == 1) continue;
		while (1)
		{

			if (choiced == '1')	// 장비에 LCD 문자 보내기
			{
				Lock_int();
				USART0_str("\r\nType your Message\r\n");
				LCD_Init();
				LCD_strout(1, 0, "Press 0 to Init");

				int index = 0;
				while (1)
				{
					while (Rflag == 0);
					char command = data;
					Rflag = 0;
					LCD_pos(0, index);
					if (command == '\r')  break;
					if (command == 8) { if (index > 0) { index--; LCD_charout(0, index, ' '); LCD_pos(0, index);  Serial_Send(' '); Serial_Send('\b'); }  continue; }
					LCD_CHAR(command);
					index++;

				}

				Init_int();

				USART0_str("\r\n\r\nReturn to Menu\r\n\r\n");

				break;

			}
			else if (choiced == '2')
			{
				while (1) {
					Init_color();
					USART0_str("\r\nSelect color 1.Green 2.Yellow 3.RED\r\n");
					char command = select(3);
					change_color(command);
					break;
				}
				break;
			}
			else if (choiced == '3')
			{
				USART0_str("\033[2J\033[H");
				USART0_str("\r\n\r\n");
				break;

			}
			else
			{
				USART0_str("Wrong choice! Enter only numbers in menu!");
			}
		}
	}

}