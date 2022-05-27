// p139 프로그램 4.9 : 미로탐색 [스택]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAZE_SIZE 6
#define MAX_STACK_SIZE 100


// ==== 프로그램 4.3 스택 코드 =====

// ==== element 형 구조체로 교체 ====
typedef struct {
	short r;
	short c;
}element;

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

element here = { 1, 0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

// 위치를 스택에 삽입
void push_loc(StackType* s, int row, int column) {
	
	// 전달받은 row, cloumn 값 중 하나라도 0보다 작을 경우
	if (row < 0 || column < 0)
		return;

	// maze[r][c]가 '1'이 아니면서 동시에 '.'이 아닌 경우
	if (maze[row][column] != '1' && maze[row][column] != '.') {
		element temp;

		temp.r = row;
		temp.c = column;
		push(s, temp); // s->data[s->top].r = row, s->data[s->top].c = column
	}
}

// 미로 출력 함수
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
	printf("\n");

	// 이차원 배열 출력을 위한 반복문
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++)
			printf(" %c ", maze[r][c]);
		printf("\n");
	}
}

int main(void) {

	int row, column;
	StackType s;

	init_stack(&s);
	
	here = entry;

	while (maze[here.r][here.c] != 'x') {
		row = here.r;
		column = here.c;

		maze[row][column] = '.';  // 현재 위치를 '.'으로 변경
		maze_print(maze);

		push_loc(&s, row - 1, column); 
		push_loc(&s, row + 1, column); 
		push_loc(&s, row, column - 1); 
		push_loc(&s, row, column + 1); 

		if (is_empty(&s)) {
			printf("실패\n");
			return;
		}
		else
			here = pop(&s);
	}

	printf("성공\n");

	return 0;

}