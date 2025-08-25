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
void Init_color(void);
void change_color(char color);



#endif /* COLOR_H_ */