// p234 : ���� ���� ����Ʈ ����
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* lLink;
	struct ListNode* rLink;
}ListNode;

// ���� ���Ḯ��Ʈ �ʱ�ȭ
void init(ListNode* head) {
	head->lLink = head->rLink = head;
}

// ���� ���Ḯ��Ʈ ��� ��� �Լ�
void print_list(ListNode* head) {
	ListNode* p;

	for (p = head->rLink; p != head; p = p->rLink)
		printf("<-| %d |-> ", p->data);
	printf("\n");
}

// ��� ��� �տ� ��带 �����ϴ� �Լ�
void Insert_node(ListNode* head, element value) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = value;
	newNode->lLink = head;
	newNode->rLink = head->rLink;
	head->rLink->lLink = newNode;
	head->rLink = newNode;
}

// Ư�� ����� �ּҸ� ���޹޾� �����ϴ� �Լ�
void delete_node(ListNode* head, ListNode* removed) {
	if (removed == head)
		return;
	removed->lLink->rLink = removed->rLink;
	removed->rLink->lLink = removed->lLink;
	free(removed);
}

int main(void) {

	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	init(head);

	printf(" < ��� ����� �տ� ��� ���� 5ȸ > \n");
	for (int i = 0; i < 5; i++) {
		Insert_node(head, i);
		print_list(head);
	}

	printf("\n < ��� ����� �� ��� ���� 5ȸ > \n");
	for (int i = 0; i < 5; i++) {
		print_list(head);
		delete_node(head, head->rLink);
	}
	
	free(head);
	return 0;
}