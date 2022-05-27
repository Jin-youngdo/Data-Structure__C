// p.118 프로그램 4.5 : 동적배열 스택 프로그램
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element; // int 자료형을 element로 치환

typedef struct {
	element* data; // data는 포인터로 정의
	int capacity;  // 현재 크기
	int top;
} StackType;

// 스택 생성 함수
void init_stack(StackType *s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

// 스택이 비어있는지 확인 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}

// 스택이 가득 차있는지 확인 함수
int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}

// 스택 반환 함수
void delete(StackType* s) {
	free(s);
}

// push() 함수
void push(StackType* s, element item) {

	if (is_full(s)) {	  // 메모리 공간이 가득 차있을 경우
		// s->capacity = 1 인 값에 *2를 해주고 메모리 재할당
		s->capacity *= 2; 
		// realloc(s->data, 8) : 동적 메모리 크기 변환 함수
		// 내용은 유지, s->data 메모리를 8byte 크기로 재할당
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

int pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--]; // 가장 위에 있는 스택 하나를 제거
}

int main(void) {

	StackType s;
	init_stack(&s); // 스택 생성 & 동적배열 선언 

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	
	printf("%d \n", pop(&s)); // 3
	printf("%d \n", pop(&s)); // 2
	printf("%d \n", pop(&s)); // 1
	printf("%d \n", pop(&s)); // error 출력 예상

	delete(&s);

	return 0;
}