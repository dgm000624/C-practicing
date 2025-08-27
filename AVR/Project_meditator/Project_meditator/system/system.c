/*
 * system.c
 *
 * Created: 2025-08-27 오전 9:20:14
 *  Author: COMPUTER
 */ 

#include "system.h"


void sendMessage()		//메뉴에서 1번 선택시 실행되는 함수
{
	Lock_int();			// 1번 사용동안 인터럽트 잠그기
	USART0_str("\r\nType your Message\r\n");
	LCD_Init();			// 아래 코드까지 합쳐서 MCU장비의 Text LED에 메시지 쿨력
	LCD_strout(1, 0, "Press 0 to Init");

	int index = 0;
	while (1)
	{
		while (Rflag == 0);
		char command = data;
		Rflag = 0;
		LCD_pos(0, index);
		if (command == '\r')  break;		// Enter 클릭시 '\r'을 읽게되고 이경우 break;
		// 백스페이스 사용시 터미널과 LCD에서 한칸씩 지우고 커서를 뒤로 한칸 되돌림
		if (command == 8) { if (index > 0) { index--; LCD_charout(0, index, ' '); LCD_pos(0, index);  Serial_Send(' '); Serial_Send('\b'); }  continue; }
		LCD_CHAR(command);
		index++;

	}

	//Lock_int()로 잠근 인터럽트 다시 활성화
	Init_int();

	USART0_str("\r\n\r\nReturn to Menu\r\n\r\n");
}

// 메뉴에서 2번 누를 경우 실행되는 함수
void remote_color()
{
	while (1) {
		Init_color();
		USART0_str("\r\nSelect color 1.Green 2.Yellow 3.RED\r\n");
		char command = select(3);
		change_color(command);
		break;
	}
}

void Init_system()
{
	DDRD = 0x00;
	PortInit();		// LCD용 초기 세팅
	LCD_Init();		// LCD 화면 클리어
	keypad_Init();	// keypad용 초기 세팅
	Init_timer();	// 타이머용 초기세팅
	Init_cds();		// cds(광센서)용 초기세팅
	Init_int();		// 인터럽트용 초기세팅
	Init_USART();	// UART(하이퍼 터미널과 소통)용 초기 세팅함수
}

void system_loading()
{
	for (int i = 0; i < 5; i++) {
		Serial_Send('=');
		_delay_ms(200);
	}
	USART0_str("\r\n");
}

void login()
{
	check_pass();		// pass등록 함수. 4자리 숫자 제한
	USART0_str("Enter password in repeater\r\n");
	while (1) {
		cli();//pass를 인증하기 전까지 인터럽트 비활성화
		if (cp_pass(pass) == 1) { USART0_str("Correct pass!\r\n"); LCD_strout(1, 0, "ACCESS"); locked = 0; Init_buff(); break; } // 인증을 맞을 경우, 잠금 해제 + 쌓인 인터럽트 제거
		else { USART0_str("Wrong pass! retry\r\n"); LCD_strout(1, 0, "RETRY"); }
			
	}
	sei();
}

void Manage_Member()
{
	char choiced = '0';
	USART0_str("\b\r\n\r\nWhat do you want? 1. Add member, 2. Delete member\r\n");
	choiced = select(2);
	USART0_str("\b\r\nEnter name : \r\n");
	receive_text();	//UART.c에 만들어둔 전역변수 temp_name[20]에 텍스트 받기
	if (choiced == '1')
	{
		USART0_str("\b\r\nWhere is it? 1. in , 2. out \r\n");
		choiced = select(2);
		if (choiced == '1') Enroll(temp_name, 1, root);			//In_out에 선언해둔 전역 객체 root를 통해 멤버 등록
		else if (choiced == '2') Enroll(temp_name, 0, root);

		reset_text();
	}
	else if (choiced == '2')
	{
		Delete(temp_name, root);
	}
}

void system_toggle()
{
	USART0_str("\b\r\n\r\n Who do you want to toggle?\r\n");
	USART0_str("\bEnter name : \r\n");
	receive_text();
	Toggle(temp_name, root);	//root에서 temp_name(UART 전역 배열)의 state를 반전시킨다.
	reset_text();				//receive_text()로 받아온 temp_name배열을 '\0'으로 초기화시킴
	USART0_str("\r\n secceed!\r\n");
}

char back()
{
	char choiced = '0';
	USART0_str("\b\r\n\r\n Who do you want to exit? 1.yes, 2.no\r\n");
	choiced = select(2);
	return choiced;
}