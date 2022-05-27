// p202 : Ư���� ���� Ž���ϴ� �Լ� ����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;

typedef struct ListNode {
	element data;			// element�� ����ü�� �̷���� ������ ����
	struct ListNode* link;	// �ڱ� �ڽ��� ������
}ListNode;

void error(char* msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	// �����޸� �Ҵ�
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
		printf("����Ʈ���� 30�� ã�ҽ��ϴ�.\n");
	else
		printf("����Ʈ���� 30�� ã�� ���߽��ϴ�. \n");

	return 0;
}