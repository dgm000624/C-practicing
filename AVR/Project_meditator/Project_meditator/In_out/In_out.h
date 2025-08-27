/*
 * In_out.h
 *
 * Created: 2025-08-26 오전 9:21:17
 *  Author: COMPUTER
 */ 


#ifndef IN_OUT_H_
#define IN_OUT_H_



typedef struct Person{
	char name[20];
	int state;
	struct Person* next;
	struct Person* prev;
} person;

person* root;

void Clear_curr(person* curr);												// 인원 삭제 이전에 curr객체 초기화용
void Enroll(char* name, int state, person* head);					// 인원 등록용
void Delete(char* name, person* head);								// 등록된 인원 삭제용
void print_list(person* head);												// 등록된 인원 정보 출력용
void Toggle(char* name, person* head);								// state 반전용
int person_LCD(int index, person* head);

#endif /* IN_OUT_H_ */