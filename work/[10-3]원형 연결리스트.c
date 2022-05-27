// p225 : 원형 연결 리스트 예제
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void print_list(ListNode* head) {
	ListNode* p = head->link;
	
	if (head == NULL)
		return;

	do {
		printf("%d -> ", p->data);
		p = p->link;
	} while (p != head);
	printf("%d -> ", p->data);
}

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

int main(void) {
	ListNode* head = NULL;

	printf("《 헤드 노드 앞에 노드 삽입 3회 수행 》\n");
	for (int i = 30; i > 0; i = i - 10)
		head = insert_first(head, i);
	print_list(head);


	printf("\n\n《 헤드 노드 뒤에 노드 삽입 3회 수행 》\n");
	for (int i = 40; i < 70; i = i + 10)
		head = insert_last(head, i);
	print_list(head);

	return 0;
}