//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h> 
//
///*
//��ǥ : �������� ����� ���� �ý��� �����. ������ ���� ���� �� �̵�, ����, ����, ���� ��ȸ ���� ��� ����.
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
////���� ���͸�(����) ���� ����
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
////���� ��ġ ���
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
////���� ���͸�(����)�� ���� ���� �����
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
//		printf("���� ���͸��� ������ �ʹ� �����ϴ�.");
//	}
//
//}
//
//// ������ �̸��� ���� ���
//void cat(char str[], folder* path)
//{
//	file* current;
//	current = path->files;
//	if (strcmp(str, current->name) == 0)
//	{
//		printf("���ϸ� : %s\n", path->files->name);
//		printf("���� ���� : %s\n", path->files->text);
//		return;
//	}
//	else
//	{
//		if (current->next == NULL)
//		{
//			printf("�׷� �̸��� ������ �������� �ʽ��ϴ�.");
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
////���� ���(����)�� �ٷ� ���� ���(���� �� ����)�� �̸� ���
//void ls(folder* path)
//{
//	folder* current = path;
//	file* c_file = path->files;
//	printf("���� ���丮�� �ִ� ������ �̸��� : %s, %s \n", current->child1->name, current->child2->name);
//	printf("���� ���丮�� �ִ� ������ �̸��� :");
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
////�Է��� ��η� �̵�. cd.�� �ֻ���(root)�� �� �ܴ̿� ����ڰ� ������ ���
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
////			printf("�ڽ� ��ΰ� �������� �ʽ��ϴ�.");
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
////		printf("�ش��ϴ� �̸��� ��ΰ� �������� �ʽ��ϴ�");
////	}
////
////}
//
////�Է��� ��η� �̵�. cd.�� �ֻ���(root)�� �� �ܴ̿� ����ڰ� ������ ���
//void cd(char str[], folder** path)
//{
//	if (((*path)->child1 == NULL) && ((*path)->child2 == NULL))
//	{
//		if (strcmp(str, ".") != 0)
//		{
//			printf("�ڽ� ��ΰ� �������� �ʽ��ϴ�.\n");
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
//		printf("�ش��ϴ� �̸��� ��ΰ� �������� �ʽ��ϴ�\n");
//	}
//}
//
////������ ���� ����
//void rm(char str[], folder** path)
//{
//	if ((*path)->child1 == NULL && (*path)->child2 == NULL && (*path)->files == NULL)
//	{
//		printf("������ �ڽ� ������ ������ �����ϴ�.\n");
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
//		printf("������ ����� �����ϴ�.");
//		return;
//	}
//}
//
//int console(folder** path)
//{
//	printf("��ɾ �Է��ϼ���\n");
//
//	char ans[100];
//	scanf_s("%s", ans, (unsigned)sizeof(ans));
//	clear_buffer();
//	if (strcmp(ans, "mkdir") == 0)
//	{
//		printf("mkdir ��ɾ �Է��߽��ϴ�. ������ ������ �̸��� �����ּ���\n");
//		scanf_s("%s", ans, (unsigned)sizeof(ans));
//		clear_buffer();
//		mkdir(ans, *path);
//		printf("�����Ϸ�\n");
//		return 0;
//	}
//	else if (strcmp(ans, "touch") == 0)
//	{
//		printf("touch ��ɾ �Է��߽��ϴ�. ������ ������ �̸��� �����ּ���\n");
//		scanf_s("%s", ans, (unsigned)sizeof(ans));
//		clear_buffer();
//		touch(ans, *path);
//		printf("�����Ϸ�\n");
//		return 0;
//	}
//	else if (strcmp(ans, "ls") == 0)
//	{
//		ls(*path);
//		printf("\n��¿Ϸ�\n");
//		return 0;
//	}
//	else if (strcmp(ans, "pwd") == 0)
//	{
//		pwd(*path);
//		printf("\n��¿Ϸ�\n");
//		return 0;
//	}
//	else if (strcmp(ans, "cd") == 0)
//	{
//		printf("cd ��ɾ �Է��߽��ϴ�. �̵��� ������ �̸��� �Է����ּ���\n");
//		scanf_s("%s", ans, (unsigned)sizeof(ans));
//		clear_buffer();
//		cd(ans, path);
//		printf("�̵��Ϸ�\n");
//		return 0;
//	}
//	else if (strcmp(ans, "rm") == 0)
//	{
//		printf("rm ��ɾ �Է��߽��ϴ�. ������ ���� �Ǵ� ������ �̸��� �Է����ּ���\n");
//		scanf_s("%s", ans, (unsigned)sizeof(ans));
//		clear_buffer();
//		rm(ans, path);
//		printf("�����Ϸ�\n");
//		return 0;
//	}
//	else if (strcmp(ans, "exit") == 0)
//	{
//		printf("exit ��ɾ �Է��߽��ϴ�. ���α׷��� �����մϴ�.\n");
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