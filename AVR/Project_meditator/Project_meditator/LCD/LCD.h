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

void PortInit(void);
void LCD_Data(Byte ch);
void LCD_Comm(Byte ch);
void LCD_CHAR(Byte c);
void LCD_STR(Byte* str);
void LCD_pos(unsigned char col, unsigned char row);
void LCD_Clear(void);
void LCD_Init(void);
void LCD_strout(int line, int location, char* message);
void LCD_charout(int line, int location, Byte message);



#endif /* LCD_H_ */