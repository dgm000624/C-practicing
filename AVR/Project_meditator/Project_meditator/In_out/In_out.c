/*
 * In_out.c
 *
 * Created: 2025-08-26 오전 9:21:06
 *  Author: COMPUTER
 */ 

#include "In_out.h"
#include <stdlib.h>
#include <string.h>
#include "../UART/UART.h"
#include "../LCD/LCD.h"
#include <stdio.h>
#include <util/delay.h>

person* root = NULL;

void Clear_curr(person* curr)
{
	
	if(curr->prev != NULL) curr->prev->next = curr->next;
	if(curr->next != NULL) curr->next->prev = curr->prev;
	
	curr->next = NULL;
	curr->prev = NULL;
}

void Enroll(char name[], int state, person* head)
{
	person* enroll = (person*)malloc(sizeof(person));
	
	if (enroll != NULL) {
		strcpy(enroll->name, name);
		enroll->state = state;
		enroll->next = NULL;
		enroll->prev = NULL;
	}
	
	person* curr;
	curr = head;
	
	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	
	curr -> next = enroll;
	enroll -> prev = curr;
}

void Delete(char* name, person* head)
{
	person* curr;
	curr = head;
	
	if (head->next == NULL) {USART0_str("There is nobody in list\r\n"); return;}
	
	while (curr != NULL)	// curr이 마지막 객체까지 name과 같은 이름을 가진 객체가 있나 비교하며 이동
	{
		if (strcmp((char*)curr->name, (char*)name) == 0) break;
		curr = curr->next;
	}
	
	if(curr == NULL)
	{	USART0_str(" ");
		USART0_str(name);
		USART0_str(" is not existed\r\n");
		return;
	}
	
	if(strcmp(curr->name, name)==0)
	{
		Clear_curr(curr);
		free(curr);	
		return;
	}
	
	USART0_str("Error\r\n");
	return;
}

void Toggle(char* name, person* head)
{
	person* curr;
	curr = head;
	
	if (head->next == NULL) {USART0_str("There is nobody in list\r\n"); return;}
	
	while (curr != NULL)	// curr이 마지막 객체까지 name과 같은 이름을 가진 객체가 있나 비교하며 이동
	{
		if (strcmp(curr->name, name) == 0) break;
		curr = curr->next;
	}
	
	if(curr == NULL)
	{	USART0_str(" ");
		USART0_str(name);
		USART0_str(" is not existed\r\n");
		return;
	}
	
	if(strcmp(curr->name, name)==0)
	{
		if (curr->state ==0) {curr->state = 1;}
		else curr->state = 0;
		
		USART0_str("State changed \r\n");
		return;
	}
	
	USART0_str("Error\r\n");
	return;
}

void print_list(person* head)
{
	if (head->next == NULL)
	{
		USART0_str("List Not existed\r\n");
		return;
	}
	person* curr = head;
	curr = curr->next;
	while(curr !=NULL)
	{
		USART0_str("\r\n Name :");
		USART0_str(curr->name);
		
		if (curr->state == 1)
		USART0_str(" is existed\r\n");
		else if (curr->state == 0)
		USART0_str(" is not existed\r\n");
		
		else
		USART0_str("Unknown");
		USART0_str("\r\n");
		curr = curr->next;
	}
}

int person_LCD(int index, person* head)
{
	person* curr = head->next;

	if (curr == NULL) {
		LCD_strout(0, 0, "No Members!");
		return 1;
	}

	int i;
	for (i = 0; i < index && curr != NULL; i++)
	curr = curr->next;

	if (curr == NULL) {
		LCD_strout(0, 0, "Final list");
		return 1;
	}

	LCD_strout(0, 0, curr->name);
	if(!(curr->state))
	{
		LCD_strout(0, 13, "OUT");
	}
	else if(curr->state)
	{
		LCD_strout(0, 13, "IN");
	}

	if (curr->next == NULL)
	LCD_strout(1, 0, "Final list");
	else if (curr->prev == head)
	LCD_strout(1, 0, "First list");
	else
	LCD_strout(1, 0, "             ");

	return 0;
}
