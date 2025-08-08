//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//struct profile {
//
//	char name[20];
//	int age;
//	double height;
//	double weight;
//	char* info;
//};
//
//void main()
//{
//	struct profile m;
//	m.age = 26;
//	m.height = 181;
//	m.weight = 95;
//	m.info = (char*)malloc(80);
//	/*m.name = "도건민";*/ // 이건 주소에다가 집어넣는 꼴이라 안됨
//	strcpy(m.name, "도건민");
//
//	printf("자기소개 : ");
//	fgets(m.info, 80, stdin);
//
//	printf("%s\n", m.name);
//	printf("%s", m.info);
//
//}