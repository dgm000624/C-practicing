//#include <stdio.h>
//#include <stdlib.h>  // rand(), srand()
//#include <time.h>    // time()
//#include <windows.h>
//
//#define SIZE 10
//
//void create_mine(int a[]);
//void print_field(int field[SIZE][SIZE]);
//void create_board(int filed[SIZE][SIZE]);
//void print_board(int field[SIZE][SIZE], int color[SIZE][SIZE]);
//void create_color(int color[SIZE][SIZE]);
//int proper(int size, int size2);
//
//
//int click(int filed[SIZE][SIZE], int board[SIZE][SIZE], int color[SIZE][SIZE], int n);
//
//int safety_tile = 0;
//
//int main()
//{
//	
//	srand(time(NULL));   // �õ� ���� (�� ����!)
//	int r = rand();
//
//	int field[SIZE][SIZE];
//	int board[SIZE][SIZE];
//	int color[SIZE][SIZE];
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		create_mine(field[i]);
//	}
//
//	create_board(board);
//	create_color(color);
//
//	print_field(field);
//	print_board(board, color);
//
//	while (1) {
//		printf("������ Ÿ���� ���� Ŭ��\n");
//		int num;
//		scanf_s("%d", &num);
//		if (click(field, board, color, num)==1)
//		{
//			break;
//		}
//		else if (click(field, board, color, num) == 2)
//		{
//			break;
//		}
//		click(field, board, color, num);
//		print_board(board, color);
//	}
//
//	return 0;
//}
//
//void create_mine(int a[])
//{
//	for (int i = 0; i < SIZE; i++)
//	{
//		int bw = rand() % 100;
//		if (bw >= 90)
//		{
//			bw = 1;
//		}
//		else if (bw < 90)
//		{
//			bw = 0;
//			safety_tile++;
//		}
//		else
//		{
//			printf("���� ���� ����");
//		}
//		a[i] = bw;
//	}
//}
//void print_field(int field[SIZE][SIZE])
//{
//	/*mine = 0;*/
//	for (int i = 0; i < SIZE; i++)
//	{
//		printf("\n");
//		for (int k = 0; k < SIZE; k++)
//		{
//			printf("%d  ", field[i][k]);
//
//			/*if (field[i][k] == 1)
//			{
//				mine++;
//			}*/
//
//		}
//	}
//	printf("\n\n");
//
//}
//
//void create_board(int field[SIZE][SIZE])
//{
//	for (int i = 0; i < SIZE; i++)
//	{
//		printf("\n");
//		for (int k = 0; k < SIZE; k++)
//		{
//			field[i][k] = k + SIZE * i;
//		}
//	}
//}
//
//void print_board(int field[SIZE][SIZE], int color[SIZE][SIZE])
//{
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	for (int i = 0; i < SIZE; i++)
//
//	{
//		printf("\n");
//		for (int k = 0; k < SIZE; k++)
//		{
//			if (color[i][k] == 1)
//			{
//				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_RED);
//				if (field[i][k] != 0)
//				{
//					printf("%d\t ", field[i][k]);
//				}
//				else {
//					printf("\t");
//				}
//				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//			}
//			else
//			{
//				if (safety_tile == 0)
//				{
//					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
//					printf("*\t ");
//				}
//				else {
//					printf("%d\t ", field[i][k]);
//				}
//				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//			}
//		}
//	}
//	printf("\n\n");
//
//	printf("���� Ÿ���� �� : %d\n" ,safety_tile);
//
//}
//void create_color(int color[SIZE][SIZE])
//{
//	for (int i = 0; i < SIZE; i++)
//	{
//		for (int k = 0; k < SIZE; k++)
//		{
//			color[i][k] = 0;
//		}
//	}
//}
//
//int click(int field[SIZE][SIZE], int board[SIZE][SIZE], int color[SIZE][SIZE], int n)
//{
//	
//
//	if ((n >= SIZE * SIZE)||(n<0))
//	{
//		return 0;
//	}
//
//	int check = 0;
//
//	const int i2 = n / SIZE;
//	const int k2 = n % SIZE;
//	if (color[i2][k2] == 1)
//	{
//		return 0;
//	}
//	board[i2][k2] = 0;
//	
//	if (field[i2][k2] == 1)
//	{
//		printf("���ڸ� ��ҽ��ϴ�. �����й�");
//		return 1;
//	}
//	else {
//		color[i2][k2] = 1;
//		for (int i = n / SIZE - 1; i <= n / SIZE + 1; i++)
//		{
//			for (int k = n % SIZE - 1; k <= n % SIZE + 1; k++)
//			{
//				if ((i < 0) || (i >= SIZE) || (k < 0) || (k >= SIZE))
//				{
//					continue;
//				}
//
//				if (field[i][k] == 1) {
//					board[i2][k2] += 1;
//					check = 1;
//				}
//				
//			}
//		}
//
//		if (check == 0)
//		{
//			// ����
//			if (k2 > 0) {
//				click(field, board, color, n - 1);
//			}
//			// ����
//			if (k2 < SIZE - 1) {
//				click(field, board, color, n + 1);
//			}
//			// ���
//			if (i2 > 0) {
//				click(field, board, color, n - SIZE);
//			}
//			// �ϴ�
//			if (i2 < SIZE - 1) {
//				click(field, board, color, n + SIZE);
//			}
//			// �»�
//			if (i2 > 0 && k2 > 0) {
//				click(field, board, color, n - SIZE - 1);
//			}
//			// ���
//			if (i2 > 0 && k2 < SIZE - 1) {
//				click(field, board, color, n - SIZE + 1);
//			}
//			// ����
//			if (i2 < SIZE - 1 && k2 > 0) {
//				click(field, board, color, n + SIZE - 1);
//			}
//			// ����
//			if (i2 < SIZE - 1 && k2 < SIZE - 1) {
//				click(field, board, color, n + SIZE + 1);
//			}
//		}
//
//		safety_tile--;
//
//		if (safety_tile == 0)
//		{
//			printf("��� ���ڸ� ã�ҽ��ϴ�. �¸�!");
//			return 2;
//		}
//		return 0;
//	}
//}
