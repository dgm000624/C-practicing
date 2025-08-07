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
//	srand(time(NULL));   // 시드 설정 (한 번만!)
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
//		printf("선택할 타일의 숫자 클릭\n");
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
//			printf("마인 생성 오류");
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
//	printf("남은 타일의 수 : %d\n" ,safety_tile);
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
//		printf("지뢰를 밟았습니다. 게임패배");
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
//			// 좌측
//			if (k2 > 0) {
//				click(field, board, color, n - 1);
//			}
//			// 우측
//			if (k2 < SIZE - 1) {
//				click(field, board, color, n + 1);
//			}
//			// 상단
//			if (i2 > 0) {
//				click(field, board, color, n - SIZE);
//			}
//			// 하단
//			if (i2 < SIZE - 1) {
//				click(field, board, color, n + SIZE);
//			}
//			// 좌상
//			if (i2 > 0 && k2 > 0) {
//				click(field, board, color, n - SIZE - 1);
//			}
//			// 우상
//			if (i2 > 0 && k2 < SIZE - 1) {
//				click(field, board, color, n - SIZE + 1);
//			}
//			// 좌하
//			if (i2 < SIZE - 1 && k2 > 0) {
//				click(field, board, color, n + SIZE - 1);
//			}
//			// 우하
//			if (i2 < SIZE - 1 && k2 < SIZE - 1) {
//				click(field, board, color, n + SIZE + 1);
//			}
//		}
//
//		safety_tile--;
//
//		if (safety_tile == 0)
//		{
//			printf("모든 지뢰를 찾았습니다. 승리!");
//			return 2;
//		}
//		return 0;
//	}
//}
