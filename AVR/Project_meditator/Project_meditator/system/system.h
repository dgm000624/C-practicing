/*
 * system.h
 *
 * Created: 2025-08-27 오전 9:20:24
 *  Author: COMPUTER
 */ 


#ifndef SYSTEM_H_
#define SYSTEM_H_

#define F_CPU 14745600UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include "../modules/keypad.h"
#include "../UART/UART.h"
#include "../LCD/LCD.h"
#include "../color_led/color.h"
#include "../interrupt/int.h"
#include "../Timer/Timer.h"
#include "../Cds/Cds.h"
#include "../In_out/In_out.h"

void sendMessage();
void remote_color();
void Init_system();
void system_loading();
void login();
void Manage_Member();
void system_toggle();
char back();
char select(int max_sel);	//버튼 인터럽트는 아니고 선택지 구분용 인터럽트



#endif /* SYSTEM_H_ */