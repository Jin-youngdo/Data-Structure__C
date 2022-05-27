// p197 ���α׷� 6.7 : �ܼ� ���� ����Ʈ
#include <stdio.h>
#include <stdlib.h>

typedef int element;

// ��� ����ü
typedef struct ListNode{
	element data;
	struct ListNode* link;	// �ڱ� ����
}ListNode;

void error(char* msg) {
	fprintf(stderr, "%s \n", msg);
	exit(1);
}

// ��� ���� �Լ�
ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = head;	
	head = p;
	
	return head;
}

// Ư�� ��ġ�� ��带 �����ϴ� �Լ�
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = pre->link;
	pre->link = p;

	return head;
}

// ��� ���� �Լ�
ListNode* delete_first(ListNode* head) {
	ListNode* removed;

	if (head == NULL)
		return NULL;
	
	removed = head;		
	head = removed->link;	

	free(removed);		
	return head;
}

// Ư�� ��ġ�� ��带 �����ϴ� �Լ�
ListNode* delete_node(ListNode* head, ListNode* pre) {
	ListNode* removed;

	removed = pre->link;
	pre->link = removed->link;

	free(removed);
	return head;
}

// Ư�� ��ġ ����� �ּҸ� ��ȯ�ϴ� �Լ�
ListNode* get_loc(ListNode* head, int index) {
	int i = 0;
	ListNode* p = head;

	while (p != NULL) {
		i++;
		if (i == index)
			return p;
		p = p->link;
	}
	return NULL;
}

// Ư�� ��ġ�� ��尡 ���� �����͸� ��ȯ�ϴ� �Լ�
element get_entry(ListNode* head, int index) {
	int i = 0;
	ListNode* p = head;

	while (p != NULL) {
		i++;
		if (i == index) 
			return p->data;
		p = p->link;
	}
	return NULL;
}

// head ���� ����� ������ data ��� �Լ�
void print_list(ListNode* head) {
	
	ListNode* p;
	
	for (p = head; p != NULL; p = p->link)
		printf("%2d   ->  ", p->data);
	printf("NULL \n");

}

int main(void) {

	ListNode* head = NULL;
	ListNode* pre = NULL;
	int index, data;

	printf(" < insert_first 3ȸ ���� >\n\n");
	for (int i = 0; i < 3; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	printf("\n\n������ ����� ��ġ(�ε���), ������ : ");
	scanf("%d %d", &index, &data);
	pre = get_loc(head, index);
	head = insert(head, pre, data);
	print_list(head);

	printf("\n\n< delete_first 4ȸ ���� > \n");
	for (int j = 0; j < 4; j++) {
		head = delete_first(head);
		print_list(head);
	}

	return 0;
}