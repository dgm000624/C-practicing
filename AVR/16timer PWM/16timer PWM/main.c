/*
 * 16timer PWM.c
 *
 * Created: 2025-08-19 오후 1:11:07
 * Author : COMPUTER
 */ 


#define F_CPU	14745600UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0x20;
	ASSR = 0;												//내부 클럭을 사용할지 비동기 외부 클럭 사용할지 설정
    TCCR1A = 0x83;											//256분주비
    TCCR1B = 0x0a;
	TCCR1C = 0x00;											// 255 + 1 _ 0x0f 
    TIMSK = 0x00;											// 인터럽트 허용											// 인터럽트 플래그(여기선 무쓸모, 자동 인터럽트 발생이 아닌 수동 처리시 필요)
	
	
	OCR1AH = 0x01;
	OCR1AL = 0x55;
	
    while (1) 
    {
	
		
    }
}
