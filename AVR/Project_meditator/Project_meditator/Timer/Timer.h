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

void Init_time();
void Init_timer();
int timer_cnt;
int second;
int timer;



#endif /* TIMER_H_ */