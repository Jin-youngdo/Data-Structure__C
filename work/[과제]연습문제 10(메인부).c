// p.143 ���� �迭�� ���� �����ϱ�[����] // ���κο��� ����(push / pop ���)
// ���� �ǵ�� ����
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define _CRT_SECURE_NO_WARNINGS


// ==== ���α׷� 4.3 ���� �ڵ� =====
typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1); // top�� 99�� ���
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

// ===== ���α׷� 4.3 ���� �ڵ� ���� ====

int main(void) {

	int arr[6];
	int i;
	int size = sizeof(arr) / sizeof(arr[0]);

	StackType s;

	init_stack(&s);

	printf("���� �迭�� ũ�� : %d\n", size);

	printf("������ �Է��Ͻÿ� : ");
	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < size; i++)
		push(&s, arr[i]);

	for (i = 0; i < size; i++)
		arr[i] = pop(&s);

	printf("������ ���� �迭 : ");
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);

	return 0;
}