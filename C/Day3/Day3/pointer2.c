//#include <stdio.h>
//
//int main()
//{
//	int ary[] = { 1,2 };
//
//	int* pary;
//	pary = ary;
//
//	/*for (int i = 0; i < sizeof(*ary); i++)
//	{
//		printf("%d", pary[i]);
//	}*/
//
//	printf("%p, %p\n", ary, pary);
//	printf("%p, %p\n", ary+1, pary+1);
//	printf("===============================\n");
//
//	char ary2[] = { 'a', 'b' };
//	pary = ary2;
//	char(*pary2) = ary2;
//	printf("%p, %p\n", ary2 + 0, pary2 + 0);
//	printf("%p, %p\n", ary2 + 1, pary2 + 1);
//	printf("===============================\n");
//
//	int ary3[2][2] = { {1,2},{3,4} };
//	int(* pary3)[2] = ary3;
//	printf("%p, %p\n", ary3, pary3);
//	printf("%p, %p\n", ary3+1, pary3+1);
//
//	return 0;
//}