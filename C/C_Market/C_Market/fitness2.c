////휘트니스 회원관리 프로그램
////노드 연결형
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
//void total_number(int count);						//전체 등록 회원수
//double average_weight(Group* pary, int count);	// 평균 체중
//int max_weight(Group* pary, int count);			// 최고 체중의 회원 index
//void print_info(Group* pary, int index);			// 회원 정보 출력
//void free_ary(Group* pary, int* count);			// 동적 할당 해제
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
//	printf("회원번호를 입력해주세요\n");
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
//	printf("이름 입력\n");
//	scanf_s("%s", &curr->name, (unsigned)_countof(curr->name));
//
//	printf("체중 입력\n");
//	scanf_s("%lf", &curr->weight);
//
//	printf("회원번호 입력\n");
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
//	printf("현재 회원의 수는 %d입니다.\n", count);
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
//	printf("현재 회원의 평균체중은 %.2f입니다.\n", total / count);
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
//	printf("현재 최대체중인 회원의 번호 %d입니다.\n", number);
//
//	return number;
//}
//void print_info(Group* pary, int num)
//{
//	Group* temp = pary->next;
//
//	if (temp == NULL || temp->customer == NULL) {
//		printf("등록된 회원이 없습니다.\n");
//		return;
//	}
//
//	while (temp != NULL)
//	{
//		if (temp->customer->num == num)
//		{
//			printf("회원님의 번호는 %d, 이름은 %s, 체중은 %.2lf입니다.\n", temp->customer->num, temp->customer->name, temp->customer->weight);
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
//	printf("등록을 해제할 회원의 번호를 입력하세요");
//	scanf_s("%d", &exit);
//
//	Group* temp = pary->next;
//	Group* prev = pary;
//
//	if (temp == NULL || temp->customer == NULL) {
//		printf("등록된 회원이 없습니다.\n");
//		return;
//	}
//
//	while (temp != NULL)
//	{
//		if (temp->customer->num == exit)
//		{
//			printf("등록을 해제합니다\n");
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