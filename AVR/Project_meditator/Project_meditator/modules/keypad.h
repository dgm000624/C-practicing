/*
 * keypad.h
 *
 * Created: 2025-08-22 오전 11:29:46
 *  Author: COMPUTER
 */


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>


#define ROWS 4	//행(입력)
#define COLS 3	//열(출력)

extern const unsigned char pads[ROWS][COLS];

extern int temp;
extern int rows;
extern int cols;

void keypad_Init();
int find_ROWS(int temp);
void reset();
char findnumber();
int cp_pass(char str[]);




#endif /* KEYPAD_H_ */