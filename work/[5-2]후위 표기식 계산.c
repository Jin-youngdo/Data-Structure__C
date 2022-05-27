// 후위 표기식 계산 [스택]
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
	return (s->top == MAX_STACK_SIZE - 1); // top이 99일 경우
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

// ===== Stack code end ====

// 후위 표기 수식 계산 함수
int eval(char exp[]) {
	int op1, op2, value, i;
	int len = strlen(exp);
	char ch;

	StackType s;
	init_stack(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];

		// 피연산자의 경우
		if (ch != '*' &&
			ch != '/' &&
			ch != '+' &&
			ch != '-') {
			value = ch - '0'; // exp[i] = ch문자 값을 아스키 코드 변환 후 연산하여 value에 전달
			push(&s, value);
		}

		// 연산자의 경우
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
	printf("후위 표기 수식 : %s\n", postfix_arr);
	result = eval(postfix_arr);
	printf("eval(\"82/3-32*+\") : %d", result);

	return 0;
}	