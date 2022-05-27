// ���� ǥ��� ��� [����]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINIGS
#define MAX_STACK_SIZE 100

// ==== Stack code =====
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

// ===== Stack code end ====

// ���� ǥ�� ���� ��� �Լ�
int eval(char exp[]) {
	int op1, op2, value, i;
	int len = strlen(exp);
	char ch;

	StackType s;
	init_stack(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];

		// �ǿ������� ���
		if (ch != '*' &&
			ch != '/' &&
			ch != '+' &&
			ch != '-') {
			value = ch - '0'; // exp[i] = ch���� ���� �ƽ�Ű �ڵ� ��ȯ �� �����Ͽ� value�� ����
			push(&s, value);
		}

		// �������� ���
		else {
			op2 = pop(&s); // s->data[top]
			op1 = pop(&s); // s->data[top-1]

			switch (ch) {
			case '+':
				push(&s, op1 + op2);
				break;
			case '-':
				push(&s, op1 - op2);
				break;
			case '*':
				push(&s, op1 * op2);
				break;
			case '/':
				push(&s, op1 / op2);
				break;
			}
		}
	}
	return pop(&s);
}

int main(void) {

	char* postfix_arr = "82/3-32*+";
	int result;
	printf("���� ǥ�� ���� : %s\n", postfix_arr);
	result = eval(postfix_arr);
	printf("eval(\"82/3-32*+\") : %d", result);

	return 0;
}	