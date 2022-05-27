// p.133 연습문제 12 : 문자열 압축[스택]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int size(StackType* s) {
	return s->top + 1;
}


void main() {
	int i;
	int letter_count; // 중복 문자열 개수
	char top;
	char line[100];

	StackType s;

	init_stack(&s); // 스택 초기화

	printf("문자열 : ");
	gets_s(line, sizeof(line));

	// 모든 문자 소문자 변환
	for (i = 0; i < strlen(line); i++) {
		line[i] = tolower(line[i]); 
	}

	printf("압축된 문자열 : ");

	for (i = 0; i < strlen(line); i++) {
		// 스택이 비어있을 경우 
		if (is_empty(&s))
			letter_count = 1;

		// 스택에 값이 존재할 경우
		if (size(&s) > 0) {
			// 스택의 top에 있는 값을 top에 전달
			top = peek(&s); 
			// 현재 s.data[s.top]에 있는 값이 전달받은 line[i]와 같을 경우
			// 다음으로 오는 문자가 이전의 문자열과 같을 경우 
			if (top == line[i])
				letter_count++;
			
			// 중복 문자가 아닌경우
			if (top != line[i]) {
				printf("%d", letter_count);
				printf("%c", top);
				letter_count = 1;
			}

			// 반복문의 마지막인 경우 (문자열의 끝인 경우)
			if (i == strlen(line) - 1) {
				printf("%d", letter_count);
				printf("%c", line[i]);
			}
		}
		push(&s, line[i]);
	}
}