/*
 * int.h
 *
 * Created: 2025-08-25 오전 9:20:04
 *  Author: COMPUTER
 */ 


#ifndef INT_H_
#define INT_H_


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void Init_int();			//초기 인터럽트 활성화
void Lock_int();			//버튼 인터럽트 비활성화
char select(int max_sel);	//버튼 인터럽트는 아니고 선택지 구분용 인터럽트
int inout_index;
int admit;

#endif /* INT_H_ */