//#include <stdio.h>			// header file
//#include <windows.h>
//#include <conio.h>
//#include <string.h>
//
//void maze();
//int maze2(int survive, const char intro[], const char sec1[], const char sec2[], const char re1[], const char re2[], const int conti);
//int issurvive(int selec, int conti);
//int horrorscene(int size);
//void termspeak(char* speak);
//void voidget(int repeat);
//
//int main()					// function head
//{							// function body
//	int continu;
//
//	continu = maze2(1, "함정의 저택에 남겨졌다.", "구조대를 기다린다", "저택을 탐험한다", "구조대의 발소리가 들린다", "수면가스에 맞아버렸다", 1);
//	int continu2 = maze2(continu, "구조대를 만났다. 하지만 뭔가 이상하다.", "구조대와 합류한다", "도망친다", "어느순간 몸이 점점 굳어간다", "구조대 형태의 인형들이 쫓아온다", 2);
//	int continu3 = maze2(continu2, "쫓아오는 인형을 어떻게 할까.", "최대한 도망친다", "싸울 무기를 찾는다", "체력이 떨어졌다", "눈 앞에 나이프가 보인다", 2);
//	int a = horrorscene(10);
//	return 0;
//}
//
//void maze() {
//	int select = 0;
//	printf("당신은 함정의 저택에 남겨졌습니다. 어떻게 해야할까요?\n 1. 구조대를 기다린다 \n2. 저택을 조사한다");
//	scanf_s("%d", &select);
//	while (1) {
//		int k = 0;
//		switch (select)
//		{
//		case 1: printf("저멀리 구조대가 다가오는 소리가 들립니다."); k = 1; break;
//		case 2: printf("당신이 저택에 발을 내딛자 갑자기 졸음이 몰려옵니다. 저 멀리 구조대의 발소리를 뒤로한채로 당신은 잠에 빠졌습니다."); k = 1; break;
//		default: printf("잘못된 값을 입력. 재입력하세요"); break;
//		}
//		if (k == 1)
//		{
//			break;
//		}
//	}
//}
//
//int maze2(int survive, const char intro[], const char sec1[], const char sec2[], const char re1[], const char re2[], const int conti)
//{
//	int select = 0;
//	survive = 0;
//
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	
//
//	while (1) {
//
//		printf("%s\n\n", intro);
//		printf("1. %s\n", sec1);
//		printf("2. %s\n", sec2);
//
//		scanf_s("%d", &select);
//		printf("\n");
//
//		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_RED);
//
//		if (select == 1)
//		{
//			printf("%s\n", re1);
//			survive = issurvive(select, conti);
//			if (survive == 1)
//			{
//				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//				break;
//			}
//		}
//		else if (select == 2){
//			printf("%s\n", re2);
//			survive = issurvive(select, conti);
//			if (survive == 1)
//			{
//				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//				break;
//			}
//		}
//		else
//		{
//			printf("1또는 2를 입력해주세요!\n\n");
//		}
//		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//	}
//	return survive;
//}
//
//// 생존여부 출력 및 결과 반환 함수. 
//int issurvive(int select, int conti)
//{
//	int survive =0;
//	if (select == conti)
//	{
//		printf("\n당신은 생존했습니다..\n\n");
//		survive = 1;
//	}
//	else if ((select == 1 || select == 2) && (select != conti)) {
//		printf("\n당신은 사망했습니다..\n");
//		printf("\n사망 시점으로 되돌아갑니다.\n\n");
//	}
//
//	return survive;
//}
//
//
//// horror
//int horrorscene(int size)
//{
//	printf("당신은 검을 집어ㄷ");
//	voidget(4);
//	printf("\b \b");
//	Sleep(1000);
//	printf("\b \b");
//	Sleep(2000);
//	printf("\b \b");
//	Sleep(1500);
//	printf("\b \b");
//	Sleep(3000);
//	for (int i = 0; i < size -4 ; i++)
//	{
//		printf("\b \b");
//	}
//	Sleep(1500);
//	system("cls");
//	
//	Sleep(1000);
//	while (_kbhit()) _getch();
//	voidget(3);
//
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
//	for (int i = 0; i < 200; i++)
//	{
//		for (int k = 0; k < 40; k++)
//		{
//			printf("드디어");
//		}
//	}
//
//	Sleep(5000);
//
//	system("cls");
//
//	printf("\n\n\n\n\n\n\n\n\t\t\t 찾았다.\n\n\n\n\n\n\n\n\n\n");
//
//	Sleep(1000);
//	while (_kbhit()) _getch();
//	voidget(1);
//
//	printf("\n당신은 사망했습니다..\n");
//
//	char regression[] = "\n사망 시점으로 되돌아갑니다.";
//
//	printf("%s", regression);
//	Sleep(1500);
//	for (int i = 0; i < strlen(regression); i++)
//	{
//		printf("\b \b");
//		Sleep(70);
//	}
//	
//	Sleep(300);
//	printf("\n\t\t\t\t");
//
//	char str[] = "어딜도망가는거야?\n\n";
//	while (_kbhit()) _getch();
//	termspeak(str);
//
//	while (1)
//	{
//		while (_kbhit()) _getch();
//		_flushall();
//		int input = getch();
//		printf("\n\t\t\t\t%c를 눌러도 소용없어\n", input);
//	}
//
//
//
//}
//
//void termspeak(char* speak)
//{
//	int i = 0;
//	while (speak[i] != '\0')
//	{
//		printf("%c", speak[i]);
//		Sleep(300);
//		i++;
//	}
//}
//
//void voidget(int repeat)
//{
//	for (int i = 0; i < repeat; i++)
//	{
//		(void)_getch();
//	}
//}
//
