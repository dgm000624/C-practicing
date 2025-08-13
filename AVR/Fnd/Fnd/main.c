/*
 * Fnd.c
 *
 * Created: 2025-08-12 오전 10:06:01
 * Author : COMPUTER
  anode: V cc	-> fnd단자는 GND
 cathode: GND -> fnd단자는 Vcc 연결
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB = 0xff;		// 포트B를 출력으로 설정
	DDRG = 0xff;		// 포트G를 출력으로 설정
	PORTG = 0x07;		// 포트G를 모두 0으로 출력(PG0 ~ PG3)
	
    while (1) 
    {
		PORTB = 0x01;
		_delay_ms(500);
		PORTB = 0x02;
		_delay_ms(500);
		PORTB = 0x04;
		_delay_ms(500);
		PORTB = 0x08;
		_delay_ms(500);
		
		PORTB = 0x10;
		_delay_ms(500);
		PORTB = 0x20;
		_delay_ms(500);
		PORTB = 0x40;
		_delay_ms(500);
		PORTB = 0x80;
		_delay_ms(500);
    }
}

