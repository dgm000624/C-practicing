/*
 * timer4.c
 *
 * Created: 2025-08-18 오후 4:17:35
 * Author : COMPUTER
 */ 

#define F_CPU	14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

static unsigned int Font[16] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86};
	
void RSegment(int);
void LSegment(int);

int tr_cnt = 0, mr_cnt = 0;
int tl_cnt = 0, ml_cnt = 0;

void RSegment(int N)
{
	int i = 0;
	unsigned char N10, N1;

	N10 = N /10;
	N1 = N % 10;
	
	for(i = 0; i<5;i++){
		
		PORTC = 0x0b;
		PORTA = ~Font[N10];
		_delay_ms(1);
		
		PORTC = 0x07;
		PORTA = ~Font[N1];
		_delay_ms(1);
	}
}

void LSegment(int N)
{
	int i = 0;
	unsigned char N10, N1;
	
	N10 = N /10;
	N1 = N % 10;
	
	for(i = 0; i<5;i++){
		
		PORTC = 0x0e;
		PORTA = ~Font[N10];
		_delay_ms(1);
		
		PORTC = 0x0d;
		PORTA = ~Font[N1];
		_delay_ms(1);
	}
}

ISR(TIMER0_OVF_vect)
{
	tr_cnt++;
	if(tr_cnt>=56){
		tr_cnt = 0;
		mr_cnt++;
		if(mr_cnt > 99) mr_cnt = 0;
	}
}

ISR(TIMER0_COMP_vect)
{
	tl_cnt++;
	if(tl_cnt>=28){
		tl_cnt = 0;
		ml_cnt++;
		if(ml_cnt > 99) ml_cnt = 0;
	}
}

int main(void)
{
	int Duty = 255;
	
	DDRB = 0x80;
	ASSR = 0;	
												//내부 클럭을 사용할지 비동기 외부 클럭 사용할지 설정
    TCCR2 = 0x6d;											//256분주비											// 255 + 1 _ 0x0f 
    TIMSK = 0x00;											// 인터럽트 허용
	TCNT2 = 0x00;
	OCR2 = 0;
    TIFR = 0;												// 인터럽트 플래그(여기선 무쓸모, 자동 인터럽트 발생이 아닌 수동 처리시 필요)


    while (1) 
    {
		_delay_ms(40);
		Duty--;
		if(Duty < 0) Duty = 255;
		OCR2 = Duty;

		
    }
}
