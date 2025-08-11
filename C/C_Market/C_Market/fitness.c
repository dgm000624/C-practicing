//��Ʈ�Ͻ� ȸ������ ���α׷�
//�迭 ������ �̿�
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

void total_number(int* count);						//��ü ��� ȸ����
double average_weight(Fitness* pary[], int* count);	// ��� ü��
int max_weight(Fitness* pary[], int* count);			// �ְ� ü���� ȸ�� index
void print_info(Fitness* pary[], int* index);			// ȸ�� ���� ���
void free_ary(Fitness* pary[], int* index, int* count);			// ���� �Ҵ� ����

int main()
{
	int count = 0;
	int select = 0;
	Fitness* group[100] = { 0 };
	
	while (1)
	{
		select = 0;
		printf("\n������ �޴��� ��ȣ ����\n");
		printf("1. ȸ�����, 2.ȸ���� ���, 3.�� ȸ���� ��� ü�� ,4.�ְ� ü�� ���, 5.ȸ�� ���� ���, 6. �������\n");
		scanf_s("%d", &select);

		if (select == 1)
		{
			
			if (count==100)
			{
				printf("���̻� ����� �Ұ����մϴ�\n");
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
			printf("���� ȸ���� ���ü���� %.2f�Դϴ�.\n", average_weight(group, &count));
		}
		else if (select == 4)
		{
			printf("���� �ִ�ü���� ȸ���� ��ȣ %d�Դϴ�.\n", group[max_weight(group, &count)]->num);
		}
		else if (select == 5)
		{
			int number = 0;
			printf("ȸ������ ȸ����ȣ�� �Է����ּ���.\n");
			scanf_s("%d", &number);
			print_info(group, &number);

		}
		else if (select == 6)
		{
			int number = 0;
			printf("Ż���Ͻ� ȸ������ ȸ����ȣ�� �Է����ּ���.\n");
			scanf_s("%d", &number);
			free_ary(group, &number, &count);
			printf("�����Ϸ�\n");

		}
		else
		{
			printf("�׸� �߿��� �Է�");
		}



	}
	

	

	return 0;
}

void enroll(Fitness* pary[], int* count)
{

	Fitness* temp = (Fitness*)malloc(sizeof(Fitness));

	printf("�̸� �Է�\n");
	scanf_s("%s", temp->name, (unsigned)_countof((temp->name)));

	printf("ü�� �Է�\n");
	scanf_s("%lf", &temp->weight);

	while (1)
	{
		printf("ȸ����ȣ �Է�\n");
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
				printf("������ ȸ����ȣ�� ������ �ٸ� ��ȣ�� �������ּ���\n");
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
	printf("���� ȸ���� ���� %d�Դϴ�.\n", *count);
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
	/*printf("���� �ִ�ü���� ȸ���� ��ȣ %d�Դϴ�.\n", pary[number]->num);*/

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
			printf("%d�� ȸ������ �̸��� %s�̰� ���� %.2lfkg�Դϴ�.\n", *index, pary[i]->name, pary[i]->weight);
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