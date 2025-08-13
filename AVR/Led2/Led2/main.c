/*
 * Led2.c
 *
 * Created: 2025-08-11 오후 3:48:29
 * Author : COMPUTER
	쉬프트
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char LED = 0x31;
	unsigned char LED2 = 0x66;
	unsigned char LED3;
    DDRE = 0xff;	//PORTE를 출력핀으로 설정
    while (1) 
    {
		/*
		PORTE = LED;
		_delay_ms(500);
		LED = LED << 1;
		if(LED == 0x80)
		{
			PORTE = LED;
			_delay_ms(500);
			PORTE = LED2;
			_delay_ms(1000);
			LED = 0x01;
		}
		*/
		
		for (int k = 0; k < 100; k++)
		{
			LED = LED >> 4;
			LED2 = LED2 >>4;
			for (int i = 0; i <4; i++)
			{
				LED3 = LED|LED2;
				PORTE = LED3;
				_delay_ms(200);
				LED = LED <<1;
				LED2 = LED2 <<1;
			}
			
			
		}
		
		/*
		PORTE = 0x80;
		_delay_ms(500);
		
		PORTE = 0x01;
		_delay_ms(500);
		
		PORTE = 0x40;
		_delay_ms(500);
		
		PORTE = 0x02;
		_delay_ms(500);
		
		PORTE = 0x20;
		_delay_ms(500);
		
		PORTE = 0x04;
		_delay_ms(500);
		
		PORTE = 0x10;
		_delay_ms(500);
		
		PORTE = 0x08;
		_delay_ms(500);
		
		PORTE = 0x00;
		
		PORTE = 0xFF;
		_delay_ms(500);
		*/
		
    }
}

