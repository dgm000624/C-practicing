/*
 * Project_meditator.c
 *
 * Created: 2025-08-22 오전 9:20:52
 * Author : COMPUTER
 */

#include "system/system.h"

int main(void)
{
	Init_system();
	Lock_int(); // 시스템 포맷은 했지만 처음엔 초소 버튼 입력이 필요치 않으므로 추후에 다시 초기화하기

	

	root = (person*)malloc(sizeof(person));

	strcpy(root->name, "");
	root->state = 0;
	root->next = NULL;
	root->prev = NULL;

	Rflag = 0;
	clear_terminal();
	
	system_loading();
	
	while (1) {
		login();
		Init_int();
		while (1)
		{	
			if (locked == 1) break;
			char choiced = '0';
			USART0_str("\b\r\n\r\nWhat you want?\r\n1. Send Text 2. Send Light 3. Clear interface\r\n4. Add/Delete Member 5. Print Members 6. Toggle In/Out 7. change pass\r\n");
			choiced = select(7);	//1~7의 선택지중 하나를 '1'같은 문자형태로 반환
			switch (choiced)
			{
			case '1':
				sendMessage();		//메시지 보내기
				break;

			case '2':
				remote_color();		// 초소 장비 color LED 색 제어
				break;

			case '3':
				clear_terminal();	// 터미널 콘솔창 화면 비우기
				break;

			case '4':
				Manage_Member();	//멤버관리(추가, 삭제)
				break;
				

			case '5':
				print_list(root);	//root에 등록되있는 모든 인원 출력
				break;

			case '6':
				system_toggle();	//멤버의 state 변경
				break;
				
			case '7':
				USART0_str("\bchange pass? 1.yes, 2.no\r\n");
				choiced = select(2);
				if(choiced == '2'){}
				else{locked = 1;}
				break;

			default:
				USART0_str("Wrong choice! Enter only numbers in menu!\r\n");
				break;
			}
		}

	}
}