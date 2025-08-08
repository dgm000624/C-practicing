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
//	struct address list[3] = { {"몹1", 20, "010 - 1111 - 1111", "조선"}, {"몹2", 21, "010 - 2222 - 2222", "고구려"}, {"몹3", 22, "010 - 3333 - 3333","고려"}};
//
//	/*for (int i = 0; i < 3; i++)
//	{
//		printf("%d번째 주소록의 이름 :%s\n",i+1, list[i].name);
//		printf("%d번째 주소록의 나이 :%d\n",i+1, list[i].age);
//		printf("%d번째 주소록의 전번 :%s\n",i+1, list[i].tel);
//		printf("%d번째 주소록의 주소 :%s\n",i+1, list[i].addr);
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
////		printf("%d번째 주소록의 이름 :%s\n", i + 1, list[i].name);
////		printf("%d번째 주소록의 나이 :%d\n", i + 1, list[i].age);
////		printf("%d번째 주소록의 전번 :%s\n", i + 1, list[i].tel);
////		printf("%d번째 주소록의 주소 :%s\n", i + 1, list[i].addr);
////	}
////}
//
//void print_list(struct address* list)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		printf("%d번째 주소록의 이름 :%s\n", i + 1, (list+i)->name);
//		printf("%d번째 주소록의 나이 :%d\n", i + 1, (list + i)->age);
//		printf("%d번째 주소록의 전번 :%s\n", i + 1, (list + i)->tel);
//		printf("%d번째 주소록의 주소 :%s\n", i + 1, (list + i)->addr);
//	}
//}