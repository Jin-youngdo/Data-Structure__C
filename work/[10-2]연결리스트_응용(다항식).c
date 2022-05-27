// p212 : ���Ḯ��Ʈ�� ������ ���׽� ���α׷�
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ��� ����ü Ÿ��
typedef struct ListNode {
	int coef;	// ���
	int expon;	// ����
	struct ListNode* link;
}ListNode;

// ��� ����ü�� �հ� �ڸ� ����ִ� ����ƮŸ�� ����ü
typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

// ���� �Լ�
void error(char* msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

// ����ƮŸ�� ����ü ���� �� �ʱ�ȭ �Լ�
ListType* create_LT() {
	ListType* pList = (ListType*)malloc(sizeof(ListType));

	pList->size = 0;
	pList->head = pList->tail = NULL;

	return pList;
}

// 
void insert_last(ListType* pList, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));

	if (temp == NULL)
		error("�޸� �Ҵ� ����");

	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	if (pList->tail == NULL)
		pList->head = pList->tail = temp;
	else {
		pList->tail->link = temp;
		pList->tail = temp;
	}
	pList->size++;
}

// ���׽� ���� �Լ�
void poly_add(ListType* pList1, ListType* pList2, ListType* result_list) {
	ListNode* a = pList1->head;
	ListNode* b = pList2->head;
	int sum;

	while (a && b) {
		// a�� ���� == b�� ����
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0)
				insert_last(result_list, sum, a->expon);
			a = a->link;
			b = b->link;
		}
		// a�� ���� > b�� ����
		else if (a->expon > b->expon) {
			insert_last(result_list, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_last(result_list, b->coef, b->expon);
			b = b->link;
		}
	}

	// a�� b�� �ϳ��� ���� ������ �Ǹ� ���� �׵��� 
	// result_list�� ����
	for (; a != NULL; a = a->link)
		insert_last(result_list, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(result_list, b->coef, b->expon);
}

void poly_print(ListType* pList) {
	ListNode* p = pList->head;
	printf("polynomial = ");
	for (; p; p = p->link)
		printf("%d^%d + ", p->coef, p->expon);
	printf("\n");
}

int main(void) {

	ListType* list1, * list2, * result_list;
	
	list1 = create_LT();
	list2 = create_LT();
	result_list = create_LT();

	// ���׽� 1 ����
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	// ���׽� 2 ����
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	poly_add(list1, list2, result_list);
	poly_print(result_list);

	free(list1); free(list2); free(result_list);
	return 0;
}