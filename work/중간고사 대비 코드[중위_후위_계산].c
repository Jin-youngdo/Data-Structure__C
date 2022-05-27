// �߰���� ��� ���� ǥ��� -> ���� ǥ��� ��ȯ -> ���� ǥ��� ��� 

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

// prec() : ������ �켱���� ��ȯ �Լ�
int prec(char op) {
	
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}

	return -1;
}

// infix_to_postfix() : ���� ǥ�� -> ���� ǥ�� ��ȯ �Լ�
void infix_to_postfix(char infix_arr[], char postfix_arr[]) {
	char ch, top_op;
	int len = strlen(infix_arr);
	int i=0, k=0;
	
	StackType s;

	init_stack(&s);

	for (i = 0; i < len; i++) {
		
		ch = infix_arr[i];

		switch (ch) {
		case '+': case '-': case '*': case '/' : 
			// ������ ������� �ʰ�, ���� ����[top]�� �ִ� �����ڰ� �켱������ ū ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				postfix_arr[k++] = pop(&s);		// postfix_arr[k++]�� ������ top�� �ִ� �� pop�ؼ� �־��ֱ�

			push(&s, ch);
			break;

		case '(':	// ���� ��ȣ�� ���� ��� ���ÿ� �߰�
			push(&s, ch);
			break;

		case ')':
			top_op = pop(&s);

			// ���� ��ȣ�� ���Ë� ���� ���ÿ� �ִ� �� ���
			// '('�� ������� top_op = pop(&s)�� ���� '(' �����ڸ� ���ÿ��� �̾Ƴ� �� break;
			// () ��ȣ �Ѵ� ���� 
			while (top_op != '(') {
				postfix_arr[k++] = top_op;
				top_op = pop(&s);
			}
			break;

		// exp[i]�� �ǿ������� ���
		default :
			postfix_arr[k++] = ch;
			break;
		}
	}

	// ���ÿ� �����ڰ� �������� ���(��� �ǿ����� ���� �Ϸ� ����)
	while (!is_empty(&s))
		postfix_arr[k++] = pop(&s);

}

// eval() : ���� ǥ�� ���� ��� �Լ�
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

	char* infix_arr = "(2+3)*(8-4)/2";
	char postfix_arr[100]="";
	int result;

	printf("���� ǥ�� ���� : %s\n", infix_arr);

	// infix_to_postfix(arr_1, arr_2) : arr_1 ����ǥ����� arr_2 ����ǥ������� ��ȯ
	infix_to_postfix(infix_arr, postfix_arr);
	
	printf("���� ǥ�� ���� : %s\n", postfix_arr);

	result = eval(postfix_arr);

	printf("���� ǥ�� ������ ��� �� : %d\n", result);
	
	return 0;
}