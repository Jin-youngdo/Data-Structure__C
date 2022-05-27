// p228 : 프로그램 7.4 멀티게임 [원형 연결리스트]
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char element[100];

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	strcpy(node->data, data);

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

int main(void) {

	ListNode* head = NULL;

	head = insert_first(head, "Kim");
	head = insert_first(head, "Park");
	head = insert_first(head, "Choi");

	ListNode* p = head;

	for (int i = 0; i < 10; i++) {
		printf("현재 차례 = %s \n", p->data);
		if ((i+1) % 3 == 0)
			printf("\n");
		p = p->link;
	}
	return 0;

}