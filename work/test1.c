#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct node {
	char data;
	struct node* pre;
}NODE;

NODE* addNode(char data) {
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->pre = NULL;
	return temp;
}

char pop(NODE** top) {
	NODE* temp = *top;
	char t;
	if (*top == NULL) return 0;
	*top = (*top)->pre;
	t = temp->data;
	free(temp);
	return t;
}

void push(NODE** top, char data) {
	NODE* temp = addNode(data);
	if (*top == NULL) {
		*top = temp;
		return;
	}
	temp->pre = *top;
	*top = temp;
}

void translate(NODE** first, NODE** second, char* input) {
	int i = 0;
	for (i = strlen(input) - 1; i >= 0; i--)
	{
		switch (input[i])
		{
		case '*':
		case '-':
		case '/':
		case '+':
			push(first, input[i]);
			break;
		case '(':
			push(second, ' ');
			push(second, pop(first));
			break;
		default:
			push(second, input[i]);
		}
	}
}

void show(NODE* top) {
	while (top != NULL) {
		if (top->data == ')') printf(" ");
		else printf("%c", top->data);
		top = top->pre;
	}
}

int main(void)
{
	NODE* FIRST = NULL;
	NODE* SECOND = NULL;
	char input[100] = "3+2+4*5+3/1";
	translate(&FIRST, &SECOND, input);
	show(SECOND);
	return 0;
}