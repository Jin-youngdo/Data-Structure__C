// p.122 ���α׷� 4.6 : ��ȣ �˻� ���α׷� [����]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100	


// ���α׷� 4.3 ���� �ڵ�
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

// ���α׷� 4.3 ���� �ڵ� ����

int check_matching(const char* in) {

    StackType s;
	char ch, open_ch;
	int n = strlen(in); // n = ���ڿ��� ����
	int push_count=0, pop_count = 0;

	init_stack(&s); // s->data ���� �޸� �Ҵ�(1byte)

	for (int i = 0; i < n; i++) {
		ch = in[i];
		
		switch (ch) {
		// ���� ��ȣ���� ������ ���
		case '(': 
		case '[':
		case '{':
			// ���ڵ��� ���ʴ�� s->data ���ÿ� ����.
			push(&s, ch);
			printf("%d��° push() ȣ�� �� stack[0] : %c, stack[1] : %c, stack[2] : %c \n", push_count + 1, s.data[0], s.data[1], s.data[2]);
			printf("s->top : %d\n", s.top);
			push_count++;
			break;
		// �ݴ� ��ȣ���� ������ ��� 
		case ')':
		case ']':
		case '}':
			if (is_empty(&s)) 
				return 0;
			else {
				// s->data[top]�� �ִ� ���ڸ� ������ open_ch�� ����.
				open_ch = pop(&s); // open_ch �� ch ���� �� () : {} : []
				printf("%d��° pop() ȣ�� �� stack[0] : %c, stack[1] : %c, stack[2] : %c \n", pop_count + 1, s.data[0], s.data[1], s.data[2]);
				printf("s->top : %d\n", s.top);
				pop_count++;
				if ((open_ch == '(' && ch != ')' ||
					 open_ch == '[' && ch != ']' ||
					 open_ch == '{' && ch != '}'))
					 return 0; // ���ǹ��� ���� �ʴ°�� 0 ��ȯ(����)
			}
			break;
		}
	}
	
	if (!is_empty(&s)) // ���ÿ� ���� ���� ��� ����
		return 1; // ���������� ������ ����� ������ ��� 1 ��ȯ(��)
}

int main(void) {

	char* p = "{ A[(i+1)]=0; }";

	if (check_matching(p) == 1)
		printf("%s ��ȣ �˻� ����\n", p);
	else
		printf("%s ��ȣ �˻� ����\n", p);

	return 0;
}