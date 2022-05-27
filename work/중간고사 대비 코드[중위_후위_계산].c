// 중간고사 대비 중위 표기식 -> 후위 표기식 변환 -> 후위 표기식 계산 

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

// prec() : 연산자 우선순위 반환 함수
int prec(char op) {
	
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}

	return -1;
}

// infix_to_postfix() : 중위 표기 -> 후위 표기 변환 함수
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
			// 스택이 비어있지 않고, 기존 스택[top]에 있는 연산자가 우선순위가 큰 경우
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				postfix_arr[k++] = pop(&s);		// postfix_arr[k++]에 스택의 top에 있는 값 pop해서 넣어주기

			push(&s, ch);
			break;

		case '(':	// 여는 괄호를 만날 경우 스택에 추가
			push(&s, ch);
			break;

		case ')':
			top_op = pop(&s);

			// 여는 괄호가 나올떄 까지 스택에 있는 값 출력
			// '('를 만날경우 top_op = pop(&s)를 통해 '(' 연산자를 스택에서 뽑아낸 후 break;
			// () 괄호 둘다 제거 
			while (top_op != '(') {
				postfix_arr[k++] = top_op;
				top_op = pop(&s);
			}
			break;

		// exp[i]가 피연산자인 경우
		default :
			postfix_arr[k++] = ch;
			break;
		}
	}

	// 스택에 연산자가 남아있을 경우(모든 피연산자 전달 완료 상태)
	while (!is_empty(&s))
		postfix_arr[k++] = pop(&s);

}

// eval() : 후위 표기 수식 계산 함수
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

	char* infix_arr = "(2+3)*(8-4)/2";
	char postfix_arr[100]="";
	int result;

	printf("중위 표기 수식 : %s\n", infix_arr);

	// infix_to_postfix(arr_1, arr_2) : arr_1 중위표기식을 arr_2 후위표기식으로 변환
	infix_to_postfix(infix_arr, postfix_arr);
	
	printf("후위 표기 수식 : %s\n", postfix_arr);

	result = eval(postfix_arr);

	printf("후위 표기 수식의 결과 값 : %d\n", result);
	
	return 0;
}