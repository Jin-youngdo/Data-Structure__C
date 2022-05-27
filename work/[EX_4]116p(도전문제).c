// p.116 �����迭 ���� ���α׷� / ���� 2�� �����Ͽ� ������ ���� Ȯ��
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
void init_stack(StackType* s) {
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
	init_stack(&s);
	StackType p;
	init_stack(&p);

	push(&s, 1); // 1
	push(&s, 2); // 2
	push(&s, 3); // 3
	// 1 - 2 - 3 ������� s->data�� ����
	// ���� s->data[top] = 3  
	// s->data[2] = 3
	// s->data[1] = 2
	// s->data[0] = 1

	push(&p, pop(&s)); // 3
	push(&p, pop(&s)); // 2
	push(&p, pop(&s)); // 1
	// 3 - 2 - 1 ������� p->data�� ���� 
	// ���� p->data[top] = 1
	// p->data[2] = 1
	// p->data[1] = 2
	// p->data[0] = 3

	printf("%d \n", pop(&p)); // 1
	printf("%d \n", pop(&p)); // 2
	printf("%d \n", pop(&p)); // 3


	delete(&s);
	delete(&p);

	return 0;
}