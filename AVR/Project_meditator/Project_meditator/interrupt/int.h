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


void Init_int();
void Lock_int();
char select(int max_sel);


#endif /* INT_H_ */