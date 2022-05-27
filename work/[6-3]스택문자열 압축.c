// p.133 �������� 12 : ���ڿ� ����[����]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

// ==== ���α׷� 4.3 ���� �ڵ� =====
typedef char element;

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

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== ���α׷� 4.3 ���� �ڵ� ���� ====

int size(StackType* s) {
	return s->top + 1;
}


void main() {
	int i;
	int letter_count; // �ߺ� ���ڿ� ����
	char top;
	char line[100];

	StackType s;

	init_stack(&s); // ���� �ʱ�ȭ

	printf("���ڿ� : ");
	gets_s(line, sizeof(line));

	// ��� ���� �ҹ��� ��ȯ
	for (i = 0; i < strlen(line); i++) {
		line[i] = tolower(line[i]); 
	}

	printf("����� ���ڿ� : ");

	for (i = 0; i < strlen(line); i++) {
		// ������ ������� ��� 
		if (is_empty(&s))
			letter_count = 1;

		// ���ÿ� ���� ������ ���
		if (size(&s) > 0) {
			// ������ top�� �ִ� ���� top�� ����
			top = peek(&s); 
			// ���� s.data[s.top]�� �ִ� ���� ���޹��� line[i]�� ���� ���
			// �������� ���� ���ڰ� ������ ���ڿ��� ���� ��� 
			if (top == line[i])
				letter_count++;
			
			// �ߺ� ���ڰ� �ƴѰ��
			if (top != line[i]) {
				printf("%d", letter_count);
				printf("%c", top);
				letter_count = 1;
			}

			// �ݺ����� �������� ��� (���ڿ��� ���� ���)
			if (i == strlen(line) - 1) {
				printf("%d", letter_count);
				printf("%c", line[i]);
			}
		}
		push(&s, line[i]);
	}
}