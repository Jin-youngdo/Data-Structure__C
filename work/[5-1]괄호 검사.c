// p.122 프로그램 4.6 : 괄호 검사 프로그램 [스택]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100	


// 프로그램 4.3 스택 코드
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

// 프로그램 4.3 스택 코드 종료

int check_matching(const char* in) {

    StackType s;
	char ch, open_ch;
	int n = strlen(in); // n = 문자열의 길이
	int push_count=0, pop_count = 0;

	init_stack(&s); // s->data 동적 메모리 할당(1byte)

	for (int i = 0; i < n; i++) {
		ch = in[i];
		
		switch (ch) {
		// 여는 괄호들을 만나는 경우
		case '(': 
		case '[':
		case '{':
			// 문자들을 차례대로 s->data 스택에 저장.
			push(&s, ch);
			printf("%d번째 push() 호출 후 stack[0] : %c, stack[1] : %c, stack[2] : %c \n", push_count + 1, s.data[0], s.data[1], s.data[2]);
			printf("s->top : %d\n", s.top);
			push_count++;
			break;
		// 닫는 괄호들을 만나는 경우 
		case ')':
		case ']':
		case '}':
			if (is_empty(&s)) 
				return 0;
			else {
				// s->data[top]에 있는 문자를 꺼내서 open_ch에 저장.
				open_ch = pop(&s); // open_ch 와 ch 값을 비교 () : {} : []
				printf("%d번째 pop() 호출 후 stack[0] : %c, stack[1] : %c, stack[2] : %c \n", pop_count + 1, s.data[0], s.data[1], s.data[2]);
				printf("s->top : %d\n", s.top);
				pop_count++;
				if ((open_ch == '(' && ch != ')' ||
					 open_ch == '[' && ch != ']' ||
					 open_ch == '{' && ch != '}'))
					 return 0; // 조건문에 맞지 않는경우 0 반환(거짓)
			}
			break;
		}
	}
	
	if (!is_empty(&s)) // 스택에 남아 있을 경우 오류
		return 1; // 정상적으로 스택이 비워진 상태일 경우 1 반환(참)
}

int main(void) {

	char* p = "{ A[(i+1)]=0; }";

	if (check_matching(p) == 1)
		printf("%s 괄호 검사 성공\n", p);
	else
		printf("%s 괄호 검사 실패\n", p);

	return 0;
}