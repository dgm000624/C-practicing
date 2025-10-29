/*
 * Cds.c
 *
 * Created: 2025-08-25 오후 2:36:18
 *  Author: COMPUTER
 */ 

#include "Cds.h"
#include "../UART/UART.h"
#include "../Timer/Timer.h"

# 광센서 수치 기록용
unsigned int adc_data = 0;

# 상태 기록용(낮, 밤)
int day = 1;

#광센서 감지 인터럽트
ISR(ADC_vect)
{	
	#광센서에 기록된 수치
	adc_data = ADCW;
	ADCSRA = ADCSRA | 0x40;

	# 광센서가 200이하가 되었고 이전이 낮이었으면 실행 / 광센서가 700초과가 되었고 이전이 밤이었으면 실행
	if(adc_data <200 && day == 1)
	{
		USART0_str("\r\nNight comes\r\n");
		day = 0;
	}
	else if(adc_data>700 && day == 0)
	{
		USART0_str("\r\nDay comes\r\n");
		day = 1;
	}	
}

void Init_cds()
{
	DDRF = 0x00;
	ADMUX = 0x03;
	ADCSRA = 0x8b;
	_delay_ms(1);
	ADCSRA |= 0x40;
}
