/*
 * color.h
 *
 * Created: 2025-08-22 오후 3:56:12
 *  Author: COMPUTER
 */


#ifndef COLOR_H_
#define COLOR_H_


#include <avr/io.h>
#include <util/delay.h>

unsigned RGB_Table[3][3];
void Init_color(void);			//color LED 사용 초기 세팅
void change_color(char color);	// color LED 색 설정용. 지금은 3가지만 설정되어있음



#endif /* COLOR_H_ */