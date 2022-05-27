// p.133 ���α׷� 4.8 : ���� ǥ��� -> ���� ǥ��� ��ȯ [����]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
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


// ������ �켱���� ��ȯ
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// ���� ǥ�� -> ���� ǥ�� ��ȯ �Լ�
void infix_to_postfix(char infix_arr[]) {
	char ch, top_op;
	int len = strlen(infix_arr);
	int i;

	StackType s;

	init_stack(&s);

	for (i = 0; i < len; i++) {

		ch = infix_arr[i];	// ch ������ ����ǥ��� ���ڸ� �ϳ��� ����

		switch (ch) {
		// �Է°��� �������� ���
		case '+': case '-': case '*': case '/':
			// ������ ������� �ʰ�, ���� ������ top�� �ִ� �������� �켱������ ũ�ų� ���� ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s)); // ���ÿ� �ִ� ���� ������ ���

			// ������ ����ְų�, ���� ������ top�� �ִ� �������� �켱������ ���� ���
			push(&s, ch); // ���ο� �������� exp[i]�� ���ÿ� �߰�
			break;

		case '(':	// ���� ��ȣ�� ���� ��� ���ÿ� �߰�
			push(&s, ch);
			break;

		case ')':	// �ݴ� ��ȣ�� ���� ��� 
			top_op = pop(&s);

			// ���� ��ȣ�� ���Ë� ���� ���ÿ� �ִ� �� ���
			// '('�� ������� top_op = pop(&s)�� ���� '(' �����ڸ� ���ÿ��� �̾Ƴ� �� break;
			// () ��ȣ �Ѵ� ���� 
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;

			// exp[i]�� �ǿ������� ��� ���
		default:
			printf("%c", ch);
			break;
		}
	}
	// ���ÿ� �����ڰ� �������� ���(��� �ǿ����� ��� �Ϸ� ����)
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

int main(void) {

	char *s = "3*(4-1)+2+8/4"; // (2+3)*4+9
	printf("���� ǥ�� ���� : %s \n", s);
	printf("���� ǥ�� ���� : ");

	infix_to_postfix(s);

	return 0;
}