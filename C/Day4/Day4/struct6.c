//#include <stdio.h>
//
//struct node {
//	int num;
//	struct node* next; // 자기 참조 구조체
//	//struct node* prev;
//};
//
//int main()
//{
//	/*struct node num1 = { 0, NULL,NULL };
//	struct node num2;
//	num2.num = 1;
//	num2.prev = &num1;
//	num1.next = &num2;
//
//	printf("%d\n", num1.next->num);
//	printf("%d\n", num1.next->prev->num);
//*/
//
//	struct node n = { 10,0 }, n1 = { 20,0 }, n2 = { 30,0 };
//	struct node* head = &n;
//
//	n.next = &n1;
//	n1.next = &n2;
//
//	printf("head->num: %d\n", head->num);
//	printf("head->next->num: %d\n", head->next->num);
//	printf("head->next->num->num: %d\n", head->next->next->num);
//
//
//
//	return 0;
//}