//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h> 
//
///*
//목표 : 리눅스와 비슷한 파일 시스템 만들기. 폴더와 파일 구현 및 이동, 삭제, 생성, 정보 조회 등의 기능 포함.
//*/
//
//typedef struct Folder folder;
//
//typedef struct File {
//	folder* parent;
//	folder* next;
//	char name[100];
//	char text[1000];
//}file;
//
//typedef struct Folder {
//	char name[100];
//	folder* parent;
//	folder* child1;
//	folder* child2;
//	file* files;
//}folder;
//
//void touch(char str[], folder* path);
//void pwd(folder* path);
//void mkdir(char str[], folder* path);
//void cat(char str[], folder* path);
//void cd(char str[], folder** path);
//void rm(char str[], folder** path);
//int console(folder** path);
//void init_file(file* file);
//void init_folder(folder* folder);
//void clear_buffer();
//void remove_folder(folder* path);
//void remove_file(folder* path);
//
//int main()
//{
//	folder root = { "root", NULL, NULL, NULL, NULL };
//
//	folder* current = &root;
//	while (1) {
//		int end = console(&current);
//		if (end == 1) break;
//	}
//
//	return 0;
//}
//
//
//
////현재 디렉터리(폴더) 파일 생성
//void touch(char str[], folder* path)
//{
//	file* newfile = (file*)malloc(sizeof(file));
//	init_file(newfile);
//	strcpy(newfile->name, str);
//	if (path->files == NULL)
//	{
//		path->files = newfile;
//
//	}
//	else
//	{
//		file* current = path->files;
//		while (current->next != NULL)
//		{
//			current = current->next;
//		}
//		current->next = newfile;
//	}
//}
//
////현재 위치 출력
//void pwd(folder* path)
//{
//	if (path->parent != NULL) {
//		pwd(path->parent);
//		printf("%s/", path->name);
//	}
//	else {
//		printf("%s/", path->name);
//		return;
//	}
//}
//
////현재 디렉터리(폴더)에 하위 폴더 만들기
//void mkdir(char str[], folder* path)
//{
//	folder* newfolder = (folder*)malloc(sizeof(folder));
//	init_folder(newfolder);
//	newfolder->parent = path;
//	strcpy(newfolder->name, str);
//	if (path->child1 == NULL)
//	{
//		path->child1 = newfolder;
//	}
//	else if (path->child2 == NULL)
//	{
//		path->child2 = newfolder;
//	}
//	else
//	{
//		printf("현재 디렉터리에 폴더가 너무 많습니다.");
//	}
//
//}
//
//// 파일의 이름과 내용 출력
//void cat(char str[], folder* path)
//{
//	file* current;
//	current = path->files;
//	if (strcmp(str, current->name) == 0)
//	{
//		printf("파일명 : %s\n", path->files->name);
//		printf("파일 내용 : %s\n", path->files->text);
//		return;
//	}
//	else
//	{
//		if (current->next == NULL)
//		{
//			printf("그런 이름의 파일은 존재하지 않습니다.");
//			return;
//		}
//		else {
//			current = current->next;
//		}
//		
//	}
//	
//}
//
////현재 경로(폴더)의 바로 하위 경로(폴더 및 파일)의 이름 출력
//void ls(folder* path)
//{
//	folder* current = path;
//	file* c_file = path->files;
//	printf("현재 디렉토리에 있는 폴더의 이름은 : %s, %s \n", current->child1->name, current->child2->name);
//	printf("현재 디렉토리에 있는 파일의 이름은 :");
//	while (c_file != NULL)
//	{
//		printf(" %s,", c_file->name);
//		c_file = c_file->next;
//	}
//	if (c_file != NULL)
//	{
//		printf("\b \b");
//	}
//}
//
////입력한 경로로 이동. cd.는 최상위(root)로 그 이외는 사용자가 지정한 대로
////void cd(char str[], folder** path)
////{
////	if (strcmp(str, '.') == 0)
////	{
////		while ((*path)->parent != NULL)
////		{
////			*path = (*path)->parent;
////		}
////		return;
////	}
////	
////
////	if (((*path)->child1 == NULL) && ((*path)->child2 == NULL))
////	{
////			printf("자식 경로가 존재하지 않습니다.");
////	}
////
////	if (((*path)->child1 != NULL) &&strcmp(str, (*path)->child1->name) == 0)
////	{
////		*path = (*path)->child1;
////	}
////	else if (((*path)->child2 != NULL) && strcmp(str, (*path)->child2->name) == 0)
////	{
////		*path = (*path)->child2;
////	}
////	else
////	{
////		printf("해당하는 이름의 경로가 존재하지 않습니다");
////	}
////
////}
//
////입력한 경로로 이동. cd.는 최상위(root)로 그 이외는 사용자가 지정한 대로
//void cd(char str[], folder** path)
//{
//	if (((*path)->child1 == NULL) && ((*path)->child2 == NULL))
//	{
//		if (strcmp(str, ".") != 0)
//		{
//			printf("자식 경로가 존재하지 않습니다.\n");
//			return;
//		}
//	}
//
//	if (strcmp(str, ".") == 0)
//	{
//		while ((*path)->parent != NULL)
//		{
//			*path = (*path)->parent;
//		}
//		return;
//	}
//
//	if (((*path)->child1 != NULL) && strcmp(str, (*path)->child1->name) == 0)
//	{
//		*path = (*path)->child1;
//	}
//	else if (((*path)->child2 != NULL) && strcmp(str, (*path)->child2->name) == 0)
//	{
//		*path = (*path)->child2;
//	}
//	else
//	{
//		printf("해당하는 이름의 경로가 존재하지 않습니다\n");
//	}
//}
//
////폴더나 파일 삭제
//void rm(char str[], folder** path)
//{
//	if ((*path)->child1 == NULL && (*path)->child2 == NULL && (*path)->files == NULL)
//	{
//		printf("삭제할 자식 폴더나 파일이 없습니다.\n");
//		return;
//	}
//	if ((*path)->child1 != NULL && strcmp(str, (*path)->child1->name) == 0)
//	{
//		remove_folder((*path)->child1);
//		(*path)->child1 = NULL;
//	}
//	else if ((*path)->child2 != NULL && strcmp(str, (*path)->child2->name) == 0)
//	{
//		remove_folder((*path)->child2);
//		(*path)->child2 = NULL;
//	}
//	else if ((*path)->files != NULL)
//	{
//		file* current = (*path)->files;
//		file* prev = NULL;
//		while (current != NULL)
//		{
//			if (strcmp(str, current->name) == 0)
//			{
//				file* temp = current;
//				free(current);
//				temp->parent->files = temp->next;
//				temp->next->parent = temp->parent;
//				return;
//			}
//			
//			current = current->next;
//		}
//		printf("삭제할 대상이 없습니다.");
//		return;
//	}
//}
//
//int console(folder** path)
//{
//	printf("명령어를 입력하세요\n");
//
//	char ans[100];
//	scanf_s("%s", ans, (unsigned)sizeof(ans));
//	clear_buffer();
//	if (strcmp(ans, "mkdir") == 0)
//	{
//		printf("mkdir 명령어를 입력했습니다. 생성할 폴더의 이름을 정해주세요\n");
//		scanf_s("%s", ans, (unsigned)sizeof(ans));
//		clear_buffer();
//		mkdir(ans, *path);
//		printf("생성완료\n");
//		return 0;
//	}
//	else if (strcmp(ans, "touch") == 0)
//	{
//		printf("touch 명령어를 입력했습니다. 생성할 파일의 이름을 정해주세요\n");
//		scanf_s("%s", ans, (unsigned)sizeof(ans));
//		clear_buffer();
//		touch(ans, *path);
//		printf("생성완료\n");
//		return 0;
//	}
//	else if (strcmp(ans, "ls") == 0)
//	{
//		ls(*path);
//		printf("\n출력완료\n");
//		return 0;
//	}
//	else if (strcmp(ans, "pwd") == 0)
//	{
//		pwd(*path);
//		printf("\n출력완료\n");
//		return 0;
//	}
//	else if (strcmp(ans, "cd") == 0)
//	{
//		printf("cd 명령어를 입력했습니다. 이동할 폴더의 이름을 입력해주세요\n");
//		scanf_s("%s", ans, (unsigned)sizeof(ans));
//		clear_buffer();
//		cd(ans, path);
//		printf("이동완료\n");
//		return 0;
//	}
//	else if (strcmp(ans, "rm") == 0)
//	{
//		printf("rm 명령어를 입력했습니다. 삭제할 폴더 또는 파일의 이름을 입력해주세요\n");
//		scanf_s("%s", ans, (unsigned)sizeof(ans));
//		clear_buffer();
//		rm(ans, path);
//		printf("삭제완료\n");
//		return 0;
//	}
//	else if (strcmp(ans, "exit") == 0)
//	{
//		printf("exit 명령어를 입력했습니다. 프로그램을 종료합니다.\n");
//		return 1;
//		
//	}
//}
//
//void init_file(file* file)
//{
//	file->parent = NULL;
//	file->next = NULL;
//	strcpy(file->name, "");
//	strcpy(file->text, "");
//}
//void init_folder(folder* folder)
//{
//	strcpy(folder->name, "");
//	folder->parent = NULL;
//	folder->child1 = NULL;
//	folder->child2 = NULL;
//	folder->files = NULL;
//}
//
//void clear_buffer()
//{
//	int c;
//	while ((c = getchar()) != '\n' && c != EOF) {}
//}
//
//void remove_folder(folder* path)
//{
//	if (path == NULL) return;
//	remove_folder(path->child1);
//	remove_folder(path->child2);
//	remove_file(path->files);
//	free(path);
//}
//void remove_file(file* current)
//{
//	file* temp;
//	while (current != NULL)
//	{
//		temp = current;
//		current = current->next;
//		free(temp);
//	}
//
//}