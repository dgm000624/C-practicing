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

	continu = maze(1, "������ ���ÿ� ��������.", "�����븦 ��ٸ���", "������ Ž���Ѵ�", "�������� �߼Ҹ��� �鸰��", "���鰡���� �¾ƹ��ȴ�", 1);
	int continu2 = maze(continu, "�����븦 ������. ������ ���� �̻��ϴ�.", "������� �շ��Ѵ�", "����ģ��", "������� ���� ���� �����", "������ ������ �������� �Ѿƿ´�", 2);
	int continu3 = maze(continu2, "�Ѿƿ��� ������ ��� �ұ�.", "�ִ��� ����ģ��", "�ο� ���⸦ ã�´�", "ü���� ��������", "�� �տ� �������� ���δ�", 2);
	int a = horrorscene(10);
	return 0;
}

//void maze() {
//	int select = 0;
//	printf("����� ������ ���ÿ� ���������ϴ�. ��� �ؾ��ұ��?\n 1. �����븦 ��ٸ��� \n2. ������ �����Ѵ�");
//	scanf_s("%d", &select);
//	while (1) {
//		int k = 0;
//		switch (select)
//		{
//		case 1: printf("���ָ� �����밡 �ٰ����� �Ҹ��� �鸳�ϴ�."); k = 1; break;
//		case 2: printf("����� ���ÿ� ���� ������ ���ڱ� ������ �����ɴϴ�. �� �ָ� �������� �߼Ҹ��� �ڷ���ä�� ����� �ῡ �������ϴ�."); k = 1; break;
//		default: printf("�߸��� ���� �Է�. ���Է��ϼ���"); break;
//		}
//		if (k == 1)
//		{
//			break;
//		}
//	}
//}

//survive : ��������, intro : ù ��Ȳ �����, sec1,2 : ������ , re1,2 : �������� ���� ��� conti: ��� �����ص� ����
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
			printf("1�Ǵ� 2�� �Է����ּ���!\n\n");
		}
		change_color("white");
	}
	return survive;
}

// �������� ��� �� ��� ��ȯ �Լ�. 
int issurvive(int select, const int conti)
{
	int survive = 0;
	if (select == conti)
	{
		printf("\n����� �����߽��ϴ�..\n\n");
		survive = 1;
	}
	else if ((select == 1 || select == 2) && (select != conti)) {
		printf("\n����� ����߽��ϴ�..\n");
		printf("\n��� �������� �ǵ��ư��ϴ�.\n\n");
	}

	return survive;
}

// Į �ݱ� ���� �ڵ�
int horrorscene(const int size)
{
	intro(size);

	story1();

	story2();

}

//speak�迭�� �ణ�� ���� �ΰ� ��ü �ؽ�Ʈ�� ����ϵ��� ��
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

//repeatȸ ��ŭ �Է� �����ϱ�
void voidget(const int repeat)
{
	for (int i = 0; i < repeat; i++)
	{
		(void)_getch();
	}
}

//"help"��� Ÿ�̹� ���� �� �� ���������� �ؽ�Ʈ ��¿�. *: BACK�� ���� "help"�� �ֿܼ��� ����� �뵵
int hidden(int timer, const char input)
{
	BACK(20);
	location(1, 5);
	if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z') || (input >= '0' && input <= '9')) {
		printf("%c�� ������ �ҿ����\n", input);
	}
	else {
		printf("�׷��� �ҿ����\n");
	}
	timer--;

}

//help�Է� ������, help�� ������� �Է��� ��� cnt�� 1�� ���� �߰��� �ѹ��̶� Ʋ���� cnt �ʱ�ȭ
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

//�� ��ȯ
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


//maze ���� Į ��� �κ� �ڵ�
void intro(const int size)
{
	printf("����� ");
	change_color("red");
	printf("Į");
	change_color("white");
	printf("�� ���");
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

//���� �۾� ���� ���� ���� �ݺ� �κ� ���� �ڵ�
void story1()
{
	change_color("red");
	for (int i = 0; i < 200; i++)
	{
		for (int k = 0; k < 40; k++)
		{
			printf("����");
		}
	}

	Sleep(5000);

	system("cls");
	location(13, 7);
	printf(" ã�Ҵ�.");
	location(10, 0);

	Sleep(1000);
	while (_kbhit()) _getch();
	voidget(1);

	printf("\n����� ����߽��ϴ�..\n");

	const char regression[] = "\n��� �������� �ǵ��ư��ϴ�.";

	printf("%s", regression);
	Sleep(1500);
	for (int i = 0; i < strlen(regression); i++)
	{
		BACK(1);
		Sleep(70);
	}

	Sleep(300);
	location(1, 6);

	const char str[] = "����������°ž�?\n\n";
	while (_kbhit()) _getch();
	termspeak(str);
}

//�ֿܼ� help�� ġ�� ������ ������ ��������. �� ������ �Է��ص� Į ��� �ڵ� ���Ĵ� ����
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
			printf("help�� ����");
			change_color("red");
		}


		while (_kbhit()) _getch();
		int input = _getch();
		cnt = roop(help, input, cnt);

		if (cnt == 4)
		{
			system("cls");
			location(13, 5);
			printf("... �� �տ�");
			change_color("yellow");
			printf("Į");
			change_color("red");
			printf("�� �������ִ�...");
			location(10, 0);
			while (1)
			{
				voidget(5);
			}
			break;
		}

		BACK(20);
		location(1, 5);
		printf("%c�� ������ �ҿ����\n", input);
		timer--;

	}
}

//n��ŭ \n, t��ŭ \t�� ��
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