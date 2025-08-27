/*
 * LCD.h
 *
 * Created: 2025-08-20 오후 1:15:47
 *  Author: COMPUTER
 */


#ifndef LCD_H_
#define LCD_H_

#define LCD_WDATA PORTC
#define LCD_WINST PORTC
#define LCD_CTRL PORTB
#define LCD_EN 2
#define LCD_RW 1
#define LCD_RS 0
#define Byte unsigned char
#define On 1
#define Off 0

void PortInit(void);									//LCD 사용을 위한 초기 세팅 함수
void LCD_Data(Byte ch);									// LCD 문자 전송 
void LCD_Comm(Byte ch);									//
void LCD_CHAR(Byte c);									//1문자만 전송시 사용
void LCD_STR(Byte* str);								//다수의 문자 전송시 사용
void LCD_pos(unsigned char col, unsigned char row);		//LCD 위치지정
void LCD_Clear(void);									//LCD 화면 클리어
void LCD_Init(void);									//LCD_Clear + 커서 위치조정
void LCD_strout(int line, int location, char* message);	// LCD_STR랑 pos 합친거
void LCD_charout(int line, int location, Byte message);	// LCD_CHAR이랑 pos합친거



#endif /* LCD_H_ */