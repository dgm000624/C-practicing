/*
 * 16timer CTC.c
 *
 * Created: 2025-08-19 오전 11:06:54
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
int t_cnt = 0;

void Segment(int N)
{
	int i;
	unsigned char N1000, N100, N10, N1;
	int Buff;
	
	N1000 = N /1000;
	Buff = N % 1000;
	
	N100 = Buff / 100;
	Buff = Buff % 100;
	 
	N10 = Buff / 10;
	N1 = Buff % 10;
	
	for(i = 0; i < 30; i++){
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



ISR(TIMER3_COMPA_vect)		//1번 타이머에서 오버플로우 발생시 실행
{
	t_cnt++;
}

int main(void)
{
    DDRA = 0xff;			// 출력문자
	DDRC = 0xff;			// 출력위치
	PORTA = 0xff;
	PORTC = 0xff;
	
	ASSR = 0;				//내부 클럭 사용
	ETIMSK = 0x10;			//타이머 3의 출력비교 A 인터럽트 발생 허용
	TCCR3A = 0;
	TCCR3B = 0x0d;			//1024분주비
	OCR3AH = 0x1c;			//상위8비트
	OCR3AL = 0x20;			//하위8비트
	TIFR = 0;
	ETIFR = 0;
	sei();
	
    while (1) 
    {
		Segment(t_cnt);
    }
}

0001110000100000
32+1024+2048+4096 = 7200

14745600 / 7200 = 2048