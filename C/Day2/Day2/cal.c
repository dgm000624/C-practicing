//#include <stdio.h>
//
//int plus(int a, int b);
//int minus(int a, int b);
//int multi(int a, int b);
//int divide(int a, int b);
//
//int main()
//{
//	int a, b;
//	char c;
//
//	while (1) {
//		printf("식 입력\n");
//		scanf_s("%d %c %d", &a, &c, sizeof(c), &b);
//
//		if (c == '+')
//		{
//
//			printf("%d + %d = %d", a, b, plus(a, b));
//		}
//		else if (c == '-')
//		{
//			printf("%d - %d = %d", a, b, minus(a, b));
//		}
//
//		else if (c == '*')
//		{
//			printf("%d * %d = %d", a, b, multi(a, b));
//		}
//
//		else if (c == '/')
//		{
//			if (b == 0)
//			{
//				printf("0으로 나누는 것은 에러를 유발합니다");
//			}
//			else { printf("%d / %d = %d", a, b, divide(a, b)); }
//
//		}
//
//		else
//		{
//			printf("입력오류");
//		}
//
//		printf("\n");
//	}
//
//
//}
//
//int plus(int a, int b)
//{
//	return a + b;
//}
//int minus(int a, int b)
//{
//	return a - b;
//}
//int multi(int a, int b)
//{
//	return a * b;
//}
//int divide(int a, int b)
//{
//	return a / b;
//}