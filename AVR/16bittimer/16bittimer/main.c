/*
 * 16bittimer.c
 *
 * Created: 2025-08-19 오전 10:01:42
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

void Segment(int N)
{
	int i;
	unsigned char N1000, N100, N10, N1;
	int Buff;
	N1000 = N/1000;
	Buff = N%1000;
	N100 = Buff/100;
	Buff = N%100;
	N10 = Buff/10;
	N1 = N%10;
	
	for(i = 0; i<30; i++)
	{
		PORTC = 0x0e;
		PORTA = Font[N1000];
		_delay_ms(1);
		
		PORTC = 0x0d;
		PORTA = Font[N100];
		_delay_ms(1);
		
		PORTC = 0x0b;
		PORTA = Font[N10];
		_delay_ms(1);
		
		PORTC = 0x07;
		PORTA = Font[N1];
		_delay_ms(1);
	}
}

ISR(TIMER1_OVF_vect)		//1번 타이머에서 오버플로우 발생시 실행
{
	TCNT1H = 0xf4;			//타이머 초기값 재초기화
	TCNT1L = 0xc0;
	t_cnt++;
	if(t_cnt >=5){			//5번 실행시 m_cnt 값을 1 올리고 초기화
		t_cnt = 0;
		m_cnt ++;
	}
}

int main(void)
{
    DDRA = 0xff;			// 출력문자
	DDRC = 0xff;			// 출력위치
	PORTA = 0xff;
	PORTC = 0xff;
	ASSR = 0;				//내부 클럭 사용
	TIMSK = 0x04;			// 타이머1 인터럽트 사용
	TCCR1A = 0;
	TCCR1B = 0x05;
	TCCR1C = 0;
	TCNT1H = 0xf4;
	TCNT1L = 0xc0;
	TIFR = 0;
	sei();
	
    while (1) 
    {
		Segment(m_cnt);
    }
}

1111010011000000
0000101100111111
0000101101000000
2048+512+256+64 = 2880
F_CPU / 2880 = 0.00512
