// p.133 프로그램 4.8 : 중위 표기식 -> 후위 표기식 변환 [스택]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 100

// ==== 프로그램 4.3 스택 코드 =====
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

// ===== 프로그램 4.3 스택 코드 종료 ====


// 연산자 우선순위 반환
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// 중위 표기 -> 후위 표기 변환 함수
void infix_to_postfix(char infix_arr[]) {
	char ch, top_op;
	int len = strlen(infix_arr);
	int i;

	StackType s;

	init_stack(&s);

	for (i = 0; i < len; i++) {

		ch = infix_arr[i];	// ch 변수에 중위표기식 문자를 하나씩 전달

		switch (ch) {
		// 입력값이 연산자인 경우
		case '+': case '-': case '*': case '/':
			// 스택이 비어있지 않고, 기존 스택의 top에 있는 연산자의 우선순위가 크거나 같은 경우
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s)); // 스택에 있는 값을 꺼내서 출력

			// 스택이 비어있거나, 기존 스택의 top에 있는 연산자의 우선순위가 작은 경우
			push(&s, ch); // 새로운 연산자인 exp[i]를 스택에 추가
			break;

		case '(':	// 여는 괄호를 만날 경우 스택에 추가
			push(&s, ch);
			break;

		case ')':	// 닫는 괄호를 만날 경우 
			top_op = pop(&s);

			// 여는 괄호가 나올떄 까지 스택에 있는 값 출력
			// '('를 만날경우 top_op = pop(&s)를 통해 '(' 연산자를 스택에서 뽑아낸 후 break;
			// () 괄호 둘다 제거 
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;

			// exp[i]가 피연산자인 경우 출력
		default:
			printf("%c", ch);
			break;
		}
	}
	// 스택에 연산자가 남아있을 경우(모든 피연산자 출력 완료 상태)
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

int main(void) {

	char *s = "3*(4-1)+2+8/4"; // (2+3)*4+9
	printf("중위 표기 수식 : %s \n", s);
	printf("후위 표기 수식 : ");

	infix_to_postfix(s);

	return 0;
}