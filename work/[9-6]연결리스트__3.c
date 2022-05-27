// p202 : 특정한 값을 탐색하는 함수 구현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;

typedef struct ListNode {
	element data;			// element형 구조체로 이루어진 데이터 선언
	struct ListNode* link;	// 자기 자신을 재참조
}ListNode;

void error(char* msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	// 동적메모리 할당
	p->data = value;
	p->link = head;
	head = p;

	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%-3d ->  ", p->data);
	printf("NULL \n");
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;
	
	while (p != NULL) {
		if (p->data == x)
			return p;
		p = p->link;
	}
}

int main(void) {

	ListNode* head = NULL;
	
	head = insert_first(head, 10);
	print_list(head);

	head = insert_first(head, 20);
	print_list(head);

	head = insert_first(head, 30);
	print_list(head);

	if (search_list(head, 30) != NULL)
		printf("리스트에서 30을 찾았습니다.\n");
	else
		printf("리스트에서 30을 찾지 못했습니다. \n");

	return 0;
}