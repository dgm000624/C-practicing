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

void keypad_Init();			// 키패드 사용 초기 세팅
int find_ROWS(int temp);	// 누른 키의 행 찾기용
void reset();				// rows, cols를 -1로 초기화
char findnumber();			// 누른 키의 숫자를 찾는 함수
int cp_pass(char str[]);	// UART 폴더의 check_pass에서 만든 pass[]와 비교하는 함수




#endif /* KEYPAD_H_ */