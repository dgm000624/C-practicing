//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int* ptr;
//	int size = 10;
//
//	ptr = (int*)malloc(sizeof(int) * size);
//
//	if (ptr == NULL)
//	{
//		printf("메모리 할당 실패");
//		return 0;
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		ptr[i] = i + 1;
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", ptr[i]);
//	}
//	return 0;
//}