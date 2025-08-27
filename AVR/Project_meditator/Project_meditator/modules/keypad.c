/*
 * keypad_pass.c
 *
 * Created: 2025-08-21 오후 3:45:35
 * Author : COMPUTER
 */

#include "keypad.h"
#include "../UART/UART.h"
#include "../LCD/LCD.h"

const unsigned char pads[ROWS][COLS] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8' , '9'}, {'*', '0', '#'} };

int temp = 0;
int rows = -1;
int cols = -1;

void keypad_Init()
{
	DDRA = 0xF0;		//상위 니블은 출력, 하위 니블은 입력
}

int find_ROWS(int temp)
{
	if ((temp & 0x01) == 1) return 0;
	else if ((temp & 0x02) == 2) return 1;
	else if ((temp & 0x04) == 4) return 2;
	else if ((temp & 0x08) == 8) return 3;
	else return -1;
}

void reset()
{
	rows = -1;
	cols = -1;
}

char findnumber()		// 입력된 문자의 행/렬 찾기용
{
	for (int i = 0; i < 3; i++)
	{
		PORTA |= (1 << (i + 4));
		_delay_us(5);
		temp = PINA;
		_delay_ms(10);

		if (((temp & 0x01) == 0x01) || ((temp & 0x02) == 0x02) || ((temp & 0x04) == 0x04) || ((temp & 0x08) == 0x08))
		{
			rows = find_ROWS(temp);
			cols = i;
		}
		PORTA &= ~(1 << (i + 4));
	}

	if ((rows == -1) || (cols == -1)) return '\0';

	return pads[rows][cols];

}



int cp_pass(char str[])		//UART의 check_pass()로 인해 생성된 pass배열을 이 함수를 통해 비교
{
	char arr[4];
	for (int k = 0; k < 4; k++)
	{
		char key = '\0';

		// 키 입력 대기 루프
		while (key == '\0')
		{
			key = findnumber();
		}

		arr[k] = key;
		LCD_charout(0,k,arr[k]);
		reset();
		_delay_ms(100);
	}

	for (int t = 0; t < 4; t++)
	{
		if (arr[t] != str[t]) {

			USART0_str(arr);
			USART0_str("is wrong! \r\n");
			for (int i = 0; i < 4; i++)
			{
				arr[i] = '\0';
			}
			LCD_strout(0,0,"     ");
			return 0;
		}
	}
	
	LCD_strout(0,0,"     ");
	
	return 1;
}






