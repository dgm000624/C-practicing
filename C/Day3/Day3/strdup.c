//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//// strcpy는 이미 메모리가 할당된 변수등에 입력할때고 strdup는 새로 할당받으며 입력이라서
//// char* str = strdup(origin)식으로 바로 대입하는거 
//int main()
//{
//	const char* origin = "Hello World!";
//
//	char* copy = strdup(origin);
//	if (copy == NULL) {		//메모리 할당 못받으면
//		perror("failed");
//		return 1;
//	}
//
//	printf("origin: %s\n", origin);
//	printf("copy: %s\n", copy);
//
//	return 0;
//}