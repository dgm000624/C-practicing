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
//	continu = maze2(1, "������ ���ÿ� ��������.", "�����븦 ��ٸ���", "������ Ž���Ѵ�", "�������� �߼Ҹ��� �鸰��", "���鰡���� �¾ƹ��ȴ�", 1);
//	int continu2 = maze2(continu, "�����븦 ������. ������ ���� �̻��ϴ�.", "������� �շ��Ѵ�", "����ģ��", "������� ���� ���� �����", "������ ������ �������� �Ѿƿ´�", 2);
//	int continu3 = maze2(continu2, "�Ѿƿ��� ������ ��� �ұ�.", "�ִ��� ����ģ��", "�ο� ���⸦ ã�´�", "ü���� ��������", "�� �տ� �������� ���δ�", 2);
//	int a = horrorscene(10);
//	return 0;
//}
//
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
//			printf("1�Ǵ� 2�� �Է����ּ���!\n\n");
//		}
//		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//	}
//	return survive;
//}
//
//// �������� ��� �� ��� ��ȯ �Լ�. 
//int issurvive(int select, int conti)
//{
//	int survive =0;
//	if (select == conti)
//	{
//		printf("\n����� �����߽��ϴ�..\n\n");
//		survive = 1;
//	}
//	else if ((select == 1 || select == 2) && (select != conti)) {
//		printf("\n����� ����߽��ϴ�..\n");
//		printf("\n��� �������� �ǵ��ư��ϴ�.\n\n");
//	}
//
//	return survive;
//}
//
//
//// horror
//int horrorscene(int size)
//{
//	printf("����� ���� ���");
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
//			printf("����");
//		}
//	}
//
//	Sleep(5000);
//
//	system("cls");
//
//	printf("\n\n\n\n\n\n\n\n\t\t\t ã�Ҵ�.\n\n\n\n\n\n\n\n\n\n");
//
//	Sleep(1000);
//	while (_kbhit()) _getch();
//	voidget(1);
//
//	printf("\n����� ����߽��ϴ�..\n");
//
//	char regression[] = "\n��� �������� �ǵ��ư��ϴ�.";
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
//	char str[] = "����������°ž�?\n\n";
//	while (_kbhit()) _getch();
//	termspeak(str);
//
//	while (1)
//	{
//		while (_kbhit()) _getch();
//		_flushall();
//		int input = getch();
//		printf("\n\t\t\t\t%c�� ������ �ҿ����\n", input);
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
