/*
 * Cds.h
 *
 * Created: 2025-08-25 오후 2:36:26
 *  Author: COMPUTER
 */ 


#include <util/delay.h>
#include <avr/interrupt.h>

unsigned int adc_data;
int day;

void Init_cds();		//cds 사용을 위한 초기 세팅용 함수