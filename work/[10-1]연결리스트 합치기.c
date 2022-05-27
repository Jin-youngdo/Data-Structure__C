// p204 : 두개의 연결 리스트 병합 함수 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = head;
	head = p;

	return head;
}

ListNode* contact_list(ListNode* head_1, ListNode* head_2) {
	if (head_1 == NULL)
		return head_2;
	else if (head_2 == NULL)
		return head_1;
	else {
		ListNode* p = head_1;
		while (p->link != NULL)
			p = p->link;
		
		p->link = head_2;
		return head_1;
	}
}

void print_list(ListNode* head) {
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("NULL \n");
}

int main(void) {

	ListNode* head_1 = NULL;
	ListNode* head_2 = NULL;

	printf(" < head_1 list > \n");
	for (int i = 60; i > 20; i = i - 10) 
		head_1 = insert_first(head_1, i);
	print_list(head_1);

	printf("\n < head_2 list > \n");
	for (int i = 20; i > 0; i = i - 10)
		head_2 = insert_first(head_2, i);
	print_list(head_2);

	ListNode* total = contact_list(head_1, head_2);
	printf("\n < head_1 + head_2 list >\n");
	print_list(total);

	return 0;
}