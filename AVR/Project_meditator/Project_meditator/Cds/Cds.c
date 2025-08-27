/*
 * Cds.c
 *
 * Created: 2025-08-25 오후 2:36:18
 *  Author: COMPUTER
 */ 

#include "Cds.h"
#include "../UART/UART.h"
#include "../Timer/Timer.h"


unsigned int adc_data = 0;
int day = 1;

ISR(ADC_vect)
{
	adc_data = ADCW;
	ADCSRA = ADCSRA | 0x40;
	
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