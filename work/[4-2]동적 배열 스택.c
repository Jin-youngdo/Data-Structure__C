// p.118 ���α׷� 4.5 : �����迭 ���� ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element; // int �ڷ����� element�� ġȯ

typedef struct {
	element* data; // data�� �����ͷ� ����
	int capacity;  // ���� ũ��
	int top;
} StackType;

// ���� ���� �Լ�
void init_stack(StackType *s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

// ������ ����ִ��� Ȯ�� �Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}

// ������ ���� ���ִ��� Ȯ�� �Լ�
int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}

// ���� ��ȯ �Լ�
void delete(StackType* s) {
	free(s);
}

// push() �Լ�
void push(StackType* s, element item) {

	if (is_full(s)) {	  // �޸� ������ ���� ������ ���
		// s->capacity = 1 �� ���� *2�� ���ְ� �޸� ���Ҵ�
		s->capacity *= 2; 
		// realloc(s->data, 8) : ���� �޸� ũ�� ��ȯ �Լ�
		// ������ ����, s->data �޸𸮸� 8byte ũ��� ���Ҵ�
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

int pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)--]; // ���� ���� �ִ� ���� �ϳ��� ����
}

int main(void) {

	StackType s;
	init_stack(&s); // ���� ���� & �����迭 ���� 

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	
	printf("%d \n", pop(&s)); // 3
	printf("%d \n", pop(&s)); // 2
	printf("%d \n", pop(&s)); // 1
	printf("%d \n", pop(&s)); // error ��� ����

	delete(&s);

	return 0;
}