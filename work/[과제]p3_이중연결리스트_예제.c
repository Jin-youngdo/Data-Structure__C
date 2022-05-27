// 11���� ���� 1 : p3. ���� ���Ḯ��Ʈ - ����, ����
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// ��� ��� �ʱ�ȭ �Լ�
void init(DListNode* phead) {
	phead->llink = phead->rlink = phead;
}

// ���� ���Ḯ��Ʈ ��� �Լ�
void print_dList(DListNode *phead) {
	DListNode* p;

	for (p = phead->rlink; p != phead; p = p->rlink)
		printf("<-%d-> ", p->data);
	printf("\n");
}

// ����� �ڿ� ��带 �����ϴ� �Լ�
void dinsert(DListNode* before, element value) {
	DListNode* p = (DListNode*)malloc(sizeof(DListNode));

	p->data = value;
	p->llink = before;
	p->rlink = before->rlink;

	before->rlink->llink = p;
	before->rlink = p;
}

// ��� ���� ����� ����� �ּҸ� ���޹޾� �����ϴ� �Լ�
void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head)
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

// Ư�� ���� ���� ����� �ּҸ� ��ȯ�ϴ� �Լ�
DListNode* search(DListNode* head, element value) {
	DListNode* p;

	for (p = head->rlink; p != head; p=p->rlink)
		if (p->data == value)
			return p;
	return NULL;
}

int main(void) {

	DListNode* head = (DListNode*)malloc(sizeof(DListNode));	// ��� ��� ����
	init(head);	// ��� ��� �ʱ�ȭ
	DListNode* find = NULL;	// Ž���� �ӽ� ��� ����

	for (int i = 10; i <= 40; i = i + 10)
		dinsert(head, i);
	printf("�� dinsert() 4ȸ ���� ��\n");
	print_dList(head);

	find = search(head, 30);	// ���� ���Ḯ��Ʈ �� data==30�� ����� �ּҸ� find�� ����
	dinsert(find, 35);			// find�� �ּ��� �ڿ� data==35�� ��带 ����
	printf("\n�� ���� ���Ḯ��Ʈ�� data==30�� ����� �ڿ� data==35�� ��� ���� ��\n");
	print_dList(head);

	find = search(head, 35);	// ���� ���Ḯ��Ʈ �� data==35�� ����� �ּҸ� find�� ����
	ddelete(head, find);		// head���� ����� data==35�� find ��带 ����
	printf("\n�� ���� ���Ḯ��Ʈ�� data==35�� ��� ���� ��\n");
	print_dList(head);

	ddelete(head, head->rlink);	// ��� ��� ���� ��� ����
	printf("\n�� ���� ���Ḯ��Ʈ�� ����� ���� ��� ���� ��\n");
	print_dList(head);

	free(head);	// head ��� ���� �޸� ��ȯ
	return 0;
}