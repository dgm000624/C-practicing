//휘트니스 회원관리 프로그램
//배열 포인터 이용
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Group;

typedef struct {
	int num;
	char name[20];
	double weight;
}Fitness;

void enroll(Fitness* pary[], int* count);

void total_number(int* count);						//전체 등록 회원수
double average_weight(Fitness* pary[], int* count);	// 평균 체중
int max_weight(Fitness* pary[], int* count);			// 최고 체중의 회원 index
void print_info(Fitness* pary[], int* index);			// 회원 정보 출력
void free_ary(Fitness* pary[], int* index, int* count);			// 동적 할당 해제

int main()
{
	int count = 0;
	int select = 0;
	Fitness* group[100] = { 0 };
	
	while (1)
	{
		select = 0;
		printf("\n실행할 메뉴의 번호 선택\n");
		printf("1. 회원등록, 2.회원수 출력, 3.현 회원의 평균 체중 ,4.최고 체중 출력, 5.회원 정보 출력, 6. 등록해제\n");
		scanf_s("%d", &select);

		if (select == 1)
		{
			
			if (count==100)
			{
				printf("더이상 등록이 불가능합니다\n");
			}
			else
			{
				enroll(group, &count);
			}
			
		}
		else if (select == 2)
		{
			total_number(&count);
		}
		else if (select == 3)
		{
			printf("현재 회원의 평균체중은 %.2f입니다.\n", average_weight(group, &count));
		}
		else if (select == 4)
		{
			printf("현재 최대체중인 회원의 번호 %d입니다.\n", group[max_weight(group, &count)]->num);
		}
		else if (select == 5)
		{
			int number = 0;
			printf("회원님의 회원번호를 입력해주세요.\n");
			scanf_s("%d", &number);
			print_info(group, &number);

		}
		else if (select == 6)
		{
			int number = 0;
			printf("탈퇴하실 회원님의 회원번호를 입력해주세요.\n");
			scanf_s("%d", &number);
			free_ary(group, &number, &count);
			printf("해제완료\n");

		}
		else
		{
			printf("항목 중에서 입력");
		}



	}
	

	

	return 0;
}

void enroll(Fitness* pary[], int* count)
{

	Fitness* temp = (Fitness*)malloc(sizeof(Fitness));

	printf("이름 입력\n");
	scanf_s("%s", temp->name, (unsigned)_countof((temp->name)));

	printf("체중 입력\n");
	scanf_s("%lf", &temp->weight);

	while (1)
	{
		printf("회원번호 입력\n");
		scanf_s("%d", &temp->num);
		
		int check = 0;

		for (int i = 0; i < 100; i++)
		{
			if (pary[i] == NULL)
			{
				continue;
			}

			if (pary[i]->num == temp->num)
			{
				printf("동일한 회원번호가 있으니 다른 번호를 선택해주세요\n");
				check = 1;
			}
		}

		if (check == 0)
		{
			break;
		}

	}

	for (int i = 0; i < 100; i++)
	{
		if (pary[i] != NULL)
		{
			i++;
			continue;
		}

		else
		{
			pary[i] = temp;
			break;
		}

	}

	(*count)++;

	return;
}

void total_number(int* count)
{
	printf("현재 회원의 수는 %d입니다.\n", *count);
}
double average_weight(Fitness* pary[], int* count)
{
	double total = 0;
	for (int i = 0; i < 100; i++)
	{
		if (pary[i] == NULL)
		{
			continue;
		}
		total += pary[i]->weight;
	}
	
	return total / (*count);
}
int max_weight(Fitness* pary[], int *count)
{
	double max = 0;
	int number = 0;
	for (int i = 0; i < 100; i++)
	{
		if (pary[i] == NULL)
		{
			continue;
		}
		if (pary[i]->weight > max)
		{
			max = pary[i]->weight;
			number = i;
		}
	}
	/*printf("현재 최대체중인 회원의 번호 %d입니다.\n", pary[number]->num);*/

	return number;
}
void print_info(Fitness* pary[], int* index)
{
	for (int i = 0; i < 100; i++)
	{
		if (pary[i] == NULL)
		{
			continue;
		}
		if (pary[i]->num == *index)
		{
			printf("%d번 회원님의 이름은 %s이고 현재 %.2lfkg입니다.\n", *index, pary[i]->name, pary[i]->weight);
			break;
		}
	}
}
void free_ary(Fitness* pary[], int* index, int* count)
{
	for (int i = 0; i < 100; i++)
	{
		if (pary[i] == NULL)
		{
			continue;
		}
		if (pary[i]->num == *index)
		{
			free(pary[i]);
			pary[i] = NULL;
			(*count)--;
			break;
		}
	}
}