//#include <stdio.h>
//
//
//struct address {
//	char name[20];
//	int age;
//	char tel[20];
//	char addr[80];
//};
//
//void print_list(struct address humans[]);
//
//
//int main()
//{
//	struct address list[3] = { {"��1", 20, "010 - 1111 - 1111", "����"}, {"��2", 21, "010 - 2222 - 2222", "����"}, {"��3", 22, "010 - 3333 - 3333","���"}};
//
//	/*for (int i = 0; i < 3; i++)
//	{
//		printf("%d��° �ּҷ��� �̸� :%s\n",i+1, list[i].name);
//		printf("%d��° �ּҷ��� ���� :%d\n",i+1, list[i].age);
//		printf("%d��° �ּҷ��� ���� :%s\n",i+1, list[i].tel);
//		printf("%d��° �ּҷ��� �ּ� :%s\n",i+1, list[i].addr);
//	}*/
//	print_list(list);
//
//
//	return 0;
//}
//
////void print_list(struct address list[])
////{
////	for (int i = 0; i < 3; i++)
////	{
////		printf("%d��° �ּҷ��� �̸� :%s\n", i + 1, list[i].name);
////		printf("%d��° �ּҷ��� ���� :%d\n", i + 1, list[i].age);
////		printf("%d��° �ּҷ��� ���� :%s\n", i + 1, list[i].tel);
////		printf("%d��° �ּҷ��� �ּ� :%s\n", i + 1, list[i].addr);
////	}
////}
//
//void print_list(struct address* list)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d��° �ּҷ��� �̸� :%s\n", i + 1, (list+i)->name);
//		printf("%d��° �ּҷ��� ���� :%d\n", i + 1, (list + i)->age);
//		printf("%d��° �ּҷ��� ���� :%s\n", i + 1, (list + i)->tel);
//		printf("%d��° �ּҷ��� �ּ� :%s\n", i + 1, (list + i)->addr);
//	}
//}