// p.143 ���� �迭�� ���� �����ϱ�[����] // �Լ����� ���� (temp swap �ÿ�)
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

void reverse_stack(StackType *s, int size) {
	int i,temp;
	int left = 0, right = size - 1;

	for (i = 0; i < size/2; i++) {
		temp = s->data[left];
		s->data[left] = s->data[right];
		s->data[right] = temp;

		left++;
		right--;
	}
}

// ===== ���α׷� 4.3 ���� �ڵ� ���� ====

int main(void) {

	int arr[6];
	int i;
	int size = sizeof(arr) / sizeof(arr[0]);

	StackType s;

	init_stack(&s);

	printf("���� �迭�� ũ�� : 6\n");

	printf("������ �Է��Ͻÿ� : ");
	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < size; i++) {
		push(&s, arr[i]);
	}

	reverse_stack(&s, size);

	printf("������ ���� �迭 : ");
	for (i = 0; i < size; i++)
		printf("%d ", s.data[i]);

	return 0;
}