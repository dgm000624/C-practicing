/*
 * LCDMain.c
 *
 * Created: 2025-08-20 오후 1:21:53
 *  Author: COMPUTER
 */ 

#define F_CPU 14745600UL
#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "LCD/LCD.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int adc_data = 0;

ISR(ADC_vect)
{
	adc_data = ADCW;
	ADCSRA = ADCSRA | 0x40;
}

unsigned int read_adc(void)
{
	ADCSRA|=0x40;
	
	while(1){
		if((ADCSRA&0x10)!=0) break;
	}
	return ADC;
}
// void LED_censor(int N)
// {
// 	if(N>900) PORTD = (0xff);
// 	else if(N>800) PORTD = (0xfe);
// 	else if(N>700) PORTD = (0xfc);
// 	else if(N>600) PORTD = (0xf8);
// 	else if(N>500) PORTD = (0xf0);
// 	else if(N>400) PORTD = (0xe0);
// 	else if(N>300) PORTD = (0xc0);
// 	else if(N>150) PORTD = (0x80);
// 	else PORTD = (0x00);
// }

int main(void)
{

	int Duty = 255;
	
	DDRB |= 0x80;
	ASSR = 0;
	//내부 클럭을 사용할지 비동기 외부 클럭 사용할지 설정
	TCCR2 = 0x6d;											//256분주비											// 255 + 1 _ 0x0f
	TIMSK = 0x00;											// 인터럽트 허용
	TCNT2 = 0x00;
	OCR2 = 0;
	TIFR = 0;
	
	
	
	//DDRD = 0xff;
	DDRF = 0x00;
	
	ADMUX = 0x03;
	ADCSRA = 0x8b;
	
	_delay_us(10);
	
	Byte str[20] = "ATmega 128";
	char str2[20]; 
	
	sei();
	
	ADCSRA |= 0x40;
	
	PortInit();
	LCD_Init();
	 
	LCD_pos(0,0);
	LCD_STR(str);

	

	DDRB |= 0x80;
	

	while (1)
	{
		/*adc_data = read_adc();*/
		sprintf(str2, "ADC : %4d", adc_data);
		LCD_pos(1,0);
		LCD_STR((Byte*)str2); 
/*		LED_censor(adc_data);*/
		Duty = adc_data/4;
		OCR2 = Duty;
	}
	return 0;
}
