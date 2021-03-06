// p.143 정수 배열의 순서 역전하기[스택] // 함수에서 구현 (temp swap 시용)
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define _CRT_SECURE_NO_WARNINGS


// ==== 프로그램 4.3 스택 코드 =====
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

// ===== 프로그램 4.3 스택 코드 종료 ====

int main(void) {

	int arr[6];
	int i;
	int size = sizeof(arr) / sizeof(arr[0]);

	StackType s;

	init_stack(&s);

	printf("정수 배열의 크기 : 6\n");

	printf("정수를 입력하시오 : ");
	for (i = 0; i < size; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < size; i++) {
		push(&s, arr[i]);
	}

	reverse_stack(&s, size);

	printf("반전된 정수 배열 : ");
	for (i = 0; i < size; i++)
		printf("%d ", s.data[i]);

	return 0;
}