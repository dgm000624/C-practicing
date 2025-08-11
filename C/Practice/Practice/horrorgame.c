#include <stdio.h>			// header file
#include <windows.h>
#include <conio.h>
#include <string.h>

#define BACK(a)		do{for(int i=0; i<a;i++) printf("\b \b");}while(0)

int maze(int survive, const char intro[], const char sec1[], const char sec2[], const char re1[], const char re2[], const int conti);
int issurvive(int selec, const int conti);
int horrorscene(const int size);
void intro(const int size);
void story1();
void story2();
void termspeak(const char* speak);
void voidget(const int repeat);
int hidden(int timer, const char input);
int roop(const char help[], const char input, int cnt);
void change_color(const char color[]);
void location(const int n, const int t);

int main()
{
	int continu;

	continu = maze(1, "함정의 저택에 남겨졌다.", "구조대를 기다린다", "저택을 탐험한다", "구조대의 발소리가 들린다", "수면가스에 맞아버렸다", 1);
	int continu2 = maze(continu, "구조대를 만났다. 하지만 뭔가 이상하다.", "구조대와 합류한다", "도망친다", "어느순간 몸이 점점 굳어간다", "구조대 형태의 인형들이 쫓아온다", 2);
	int continu3 = maze(continu2, "쫓아오는 인형을 어떻게 할까.", "최대한 도망친다", "싸울 무기를 찾는다", "체력이 떨어졌다", "눈 앞에 나이프가 보인다", 2);
	int a = horrorscene(10);
	return 0;
}

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

//survive : 생존여부, intro : 첫 상황 설명글, sec1,2 : 선택지 , re1,2 : 선택지에 대한 결과 conti: 계속 진행해도 될지
int maze(int survive, const char intro[], const char sec1[], const char sec2[], const char re1[], const char re2[], const int conti)
{
	int select = 0;
	survive = 0;

	while (1) {

		printf("%s\n\n", intro);
		printf("1. %s\n", sec1);
		printf("2. %s\n", sec2);

		scanf_s("%d", &select);
		printf("\n");

		if (select == conti)
		{
			change_color("yellow");
		}
		else
		{
			change_color("red");
		}

		if (select == 1)
		{
			printf("%s\n", re1);
			survive = issurvive(select, conti);
			if (survive == 1)
			{
				change_color("white");
				break;
			}
		}
		else if (select == 2) {
			printf("%s\n", re2);
			survive = issurvive(select, conti);
			if (survive == 1)
			{
				change_color("white");
				break;
			}
		}
		else
		{
			printf("1또는 2를 입력해주세요!\n\n");
		}
		change_color("white");
	}
	return survive;
}

// 생존여부 출력 및 결과 반환 함수. 
int issurvive(int select, const int conti)
{
	int survive = 0;
	if (select == conti)
	{
		printf("\n당신은 생존했습니다..\n\n");
		survive = 1;
	}
	else if ((select == 1 || select == 2) && (select != conti)) {
		printf("\n당신은 사망했습니다..\n");
		printf("\n사망 시점으로 되돌아갑니다.\n\n");
	}

	return survive;
}

// 칼 줍기 이후 코드
int horrorscene(const int size)
{
	intro(size);

	story1();

	story2();

}

//speak배열을 약간의 텀을 두고 전체 텍스트를 출력하도록 함
void termspeak(const char* speak)
{
	int i = 0;
	while (speak[i] != '\0')
	{
		printf("%c", speak[i]);
		Sleep(200);
		i++;
	}
}

//repeat회 만큼 입력 낭비하기
void voidget(const int repeat)
{
	for (int i = 0; i < repeat; i++)
	{
		(void)_getch();
	}
}

//"help"출력 타이밍 조절 및 그 이전까지의 텍스트 출력용. *: BACK는 이전 "help"를 콘솔에서 지우는 용도
int hidden(int timer, const char input)
{
	BACK(20);
	location(1, 5);
	if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z') || (input >= '0' && input <= '9')) {
		printf("%c를 눌러도 소용없어\n", input);
	}
	else {
		printf("그래도 소용없어\n");
	}
	timer--;

}

//help입력 반응용, help를 순서대로 입력할 경우 cnt가 1씩 증가 중간에 한번이라도 틀리면 cnt 초기화
int roop(const char help[], const char input, int cnt)
{
	if (help[cnt] == input)
	{
		cnt++;
	}
	else
	{
		cnt = 0;
	}

	return cnt;

}

//색 변환
void change_color(const char color[])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (strcmp(color, "yellow") == 0)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	else if (strcmp(color, "red") == 0)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	}
	else if (strcmp(color, "white") == 0)
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
}


//maze 이후 칼 드는 부분 코드
void intro(const int size)
{
	printf("당신은 ");
	change_color("red");
	printf("칼");
	change_color("white");
	printf("을 집어ㄷ");
	voidget(4);
	BACK(1);
	Sleep(1000);
	BACK(1);
	Sleep(2000);
	BACK(1);
	Sleep(1500);
	BACK(1);
	Sleep(3000);
	BACK((size - 4));
	Sleep(1500);
	system("cls");

	Sleep(1000);
	while (_kbhit()) _getch();
	voidget(3);
}

//붉은 글씨 등장 이후 무한 반복 부분 이전 코드
void story1()
{
	change_color("red");
	for (int i = 0; i < 200; i++)
	{
		for (int k = 0; k < 40; k++)
		{
			printf("드디어");
		}
	}

	Sleep(5000);

	system("cls");
	location(13, 7);
	printf(" 찾았다.");
	location(10, 0);

	Sleep(1000);
	while (_kbhit()) _getch();
	voidget(1);

	printf("\n당신은 사망했습니다..\n");

	const char regression[] = "\n사망 시점으로 되돌아갑니다.";

	printf("%s", regression);
	Sleep(1500);
	for (int i = 0; i < strlen(regression); i++)
	{
		BACK(1);
		Sleep(70);
	}

	Sleep(300);
	location(1, 6);

	const char str[] = "어딜도망가는거야?\n\n";
	while (_kbhit()) _getch();
	termspeak(str);
}

//콘솔에 help를 치지 않으면 루프에 갖히게함. 단 헬프를 입력해도 칼 드는 코드 이후는 루프
void story2() {
	int timer = 10;
	int cnt = 0;
	const char help[] = "help";
	while (1)
	{
		if (timer <= 0)
		{
			change_color("yellow");
			location(0, 13);
			printf("help를 눌러");
			change_color("red");
		}


		while (_kbhit()) _getch();
		int input = _getch();
		cnt = roop(help, input, cnt);

		if (cnt == 4)
		{
			system("cls");
			location(13, 5);
			printf("... 눈 앞에");
			change_color("yellow");
			printf("칼");
			change_color("red");
			printf("이 떨어져있다...");
			location(10, 0);
			while (1)
			{
				voidget(5);
			}
			break;
		}

		BACK(20);
		location(1, 5);
		printf("%c를 눌러도 소용없어\n", input);
		timer--;

	}
}

//n만큼 \n, t만큼 \t를 함
void location(const int n, const int t)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n");
	}
	for (int k = 0; k < t; k++)
	{
		printf("\t");
	}
}