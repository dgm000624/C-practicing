////��Ʈ�Ͻ� ȸ������ ���α׷�
////��� ������
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct Group;
//
//typedef struct {
//	int num;
//	char name[20];
//	double weight;
//}Fitness;
//
//typedef struct Group {
//	struct Group* next;
//	Fitness* customer;
//}Group;
//
//Group* fitness_enroll(Group* index, int* count);
//Group* temp_customer(Group* index, int* count);
//
//void total_number(int count);						//��ü ��� ȸ����
//double average_weight(Group* pary, int count);	// ��� ü��
//int max_weight(Group* pary, int count);			// �ְ� ü���� ȸ�� index
//void print_info(Group* pary, int index);			// ȸ�� ���� ���
//void free_ary(Group* pary, int* count);			// ���� �Ҵ� ����
//
//int main()
//{
//	int count = 0;
//	int temp = 0;
//	Group* header = (Group*)malloc(sizeof(Group));
//	header->next = NULL;
//	header->customer = NULL;
//
//	for (int i = 0; i < 3; i++)
//	{
//		temp_customer(header, &count);
//	}
//
//	fitness_enroll(header, &count);
//	total_number(count);
//	average_weight(header, count);
//	printf("ȸ����ȣ�� �Է����ּ���\n");
//	
//	scanf_s("%d", &temp);
//	print_info(header, temp);
//
//	free_ary(header, &count);
//
//
//
//
//	return 0;
//}
//
//Group* fitness_enroll(Group* head, int* count)
//{
//	Fitness* curr = (Fitness*)malloc(sizeof(Fitness));
//	Group* newgroup = (Group*)malloc(sizeof(Group));
//	newgroup->next = NULL;
//	newgroup->customer = curr;
//
//	printf("�̸� �Է�\n");
//	scanf_s("%s", &curr->name, (unsigned)_countof(curr->name));
//
//	printf("ü�� �Է�\n");
//	scanf_s("%lf", &curr->weight);
//
//	printf("ȸ����ȣ �Է�\n");
//	scanf_s("%d", &curr->num);
//
//	Group* temp = head;
//	while (temp->next != NULL) {
//		temp = temp->next;
//	}
//	temp->next = newgroup;
//
//	(*count)++;
//	return head;
//}
//Group* temp_customer(Group* head, int* count)
//{
//	Fitness* curr = (Fitness*)malloc(sizeof(Fitness));
//	Group* newgroup = (Group*)malloc(sizeof(Group));
//	newgroup->next = NULL;
//	newgroup->customer = curr;
//
//	strcpy(curr->name, "temp");
//	curr->weight = 80.50;
//	curr->num = (*count);
//	
//
//
//	Group* temp = head;
//	while (temp->next != NULL) {
//		temp = temp->next;
//	}
//	temp->next = newgroup;
//
//	(*count)++;
//	return head;
//}
//
//
//
//void total_number(int count)
//{
//	printf("���� ȸ���� ���� %d�Դϴ�.\n", count);
//}
//double average_weight(Group* pary, int count)
//{
//	Group* temp;
//	temp = pary->next;
//	double total = 0;
//	for (int i = 0; i < count; i++)
//	{
//		total += temp->customer->weight;
//		temp = temp->next;
//	}
//
//	printf("���� ȸ���� ���ü���� %.2f�Դϴ�.\n", total / count);
//
//	return total / count;
//}
//int max_weight(Group* pary, int count)
//{
//	double max = 0;
//	int number = 0;
//	for (int i = 0; i < count; i++)
//	{
//		if (pary->customer->weight > max)
//		{
//			max = pary->customer->weight;
//			number = pary->customer->num;
//		}
//		pary = pary->next;
//	}
//	printf("���� �ִ�ü���� ȸ���� ��ȣ %d�Դϴ�.\n", number);
//
//	return number;
//}
//void print_info(Group* pary, int num)
//{
//	Group* temp = pary->next;
//
//	if (temp == NULL || temp->customer == NULL) {
//		printf("��ϵ� ȸ���� �����ϴ�.\n");
//		return;
//	}
//
//	while (temp != NULL)
//	{
//		if (temp->customer->num == num)
//		{
//			printf("ȸ������ ��ȣ�� %d, �̸��� %s, ü���� %.2lf�Դϴ�.\n", temp->customer->num, temp->customer->name, temp->customer->weight);
//			return;
//		}
//		temp = temp->next;
//	}
//
//	return;
//}
//void free_ary(Group* pary, int* count)
//{
//	int exit;
//
//	printf("����� ������ ȸ���� ��ȣ�� �Է��ϼ���");
//	scanf_s("%d", &exit);
//
//	Group* temp = pary->next;
//	Group* prev = pary;
//
//	if (temp == NULL || temp->customer == NULL) {
//		printf("��ϵ� ȸ���� �����ϴ�.\n");
//		return;
//	}
//
//	while (temp != NULL)
//	{
//		if (temp->customer->num == exit)
//		{
//			printf("����� �����մϴ�\n");
//			if (temp->next != NULL)
//			{
//				prev->next = temp->next;
//			}
//			else
//			{
//				prev->next = NULL;
//			}
//
//			free(temp->customer);
//			free(temp);
//			(*count)--;
//
//			return;
//		}
//		prev = temp;
//		temp = temp->next;
//	}
//}