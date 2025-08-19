/*
 * FND1.c
 *
 * Created: 2025-08-18 오전 9:43:11
 * Author : COMPUTER
 */ 

#define F_CPU	14745600UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

static unsigned int Font[16] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86};
	
void Segment(int);

int t_cnt = 0, m_cnt = 0, cnt = 0;

void Segment(int N)
{
	unsigned char N1000, N100, N10, N1;
	int Buff;
	
	N1000 = N/1000;
	Buff = N % 1000;
	N100 = Buff/100;
	Buff = Buff % 100;
	N10 = Buff /10;
	N1 = Buff % 10;
	
	for( int i = 0; i<30;i++){
		PORTC = 0x0e;
		PORTA = ~Font[N1000];
		_delay_ms(1);
		
		PORTC = 0x0d;
		PORTA = ~Font[N100];
		_delay_ms(1);
		
		PORTC = 0x0b;
		PORTA = ~Font[N10];
		_delay_ms(1);
		
		PORTC = 0x07;
		PORTA = ~Font[N1];
		_delay_ms(1);
	}
}

ISR(TIMER2_OVF_vect)
{
	cli();
	TCNT2 = 0x70;
	cnt++;
	if(cnt==4)
	{
		t_cnt++;
		cnt = 0;
	}
	if(t_cnt >=100){
		t_cnt = 0;
		m_cnt ++;
	}
	sei();
}

int main(void)
{
	DDRA = 0xff;
    DDRC = 0x0f;
	PORTA = 0xff;
	PORTC = 0x0f;
	//ASSR = 0;												//내부 클럭을 사용할지 비동기 외부 클럭 사용할지 설정
    TCCR2 = 0x04;											//256분주비
    TCNT2 = 0x70;											// 255 + 1 _ 0x0f 
    TIMSK = 0x40;											// 인터럽트 허용
    TIFR = 0;												// 인터럽트 플래그(여기선 무쓸모, 자동 인터럽트 발생이 아닌 수동 처리시 필요)
    sei();

    while (1) 
    {
		Segment(m_cnt);
    }
}
