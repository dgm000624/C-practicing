/*
 * 16timer2.c
 *
 * Created: 2025-08-19 오전 10:23:46
 * Author : COMPUTER
 */ 

#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char Font[18] = {0x3F, 0X06, 0X5B, 0X4F,
	0X66, 0X6D, 0X7C, 0X07,
	0X7F, 0X67, 0X77, 0X7C,
	0X39, 0X5E, 0X79, 0X71,
0X08, 0X80};

void Segment(int);
int t_cnt = 0, m_cnt = 0;

int led = 0x01;



ISR(TIMER3_OVF_vect)		//1번 타이머에서 오버플로우 발생시 실행
{
	TCNT3H = 0xf4;			//타이머 초기값 재초기화
	TCNT3L = 0xc0;
	t_cnt++;
	if(t_cnt >=1){			//5번 실행시 m_cnt 값을 1 올리고 초기화
		t_cnt = 0;
		m_cnt ++;
		led = led +1;
		if (led == 256) led = 0x01;
	}
}

int main(void)
{
//     DDRA = 0xff;			// 출력문자
// 	DDRC = 0xff;			// 출력위치
// 	PORTA = 0xff;
// 	PORTC = 0xff;

	DDRE = 0xff;
	
	
	ASSR = 0;				//내부 클럭 사용
	ETIMSK = 0x04; 
	TCCR3A = 0;
	TCCR3B = 0x05;
	TCCR3C = 0;
	TCNT3H = 0xf4;
	TCNT3L = 0xc0;
	TIFR = 0;
	sei();
	
    while (1) 
    {
		PORTE = led;
    }
}


