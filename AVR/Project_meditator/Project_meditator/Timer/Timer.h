/*
 * Timer.h
 *
 * Created: 2025-08-25 오전 10:35:27
 *  Author: COMPUTER
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void Init_time();	// 타이머 초기화용
void Init_timer();	// 타이머 초기세팅용
int timer_cnt;
int second;
int timer;



#endif /* TIMER_H_ */