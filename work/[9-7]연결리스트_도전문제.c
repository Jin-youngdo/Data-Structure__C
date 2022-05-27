// 단순 연결리스트에서의 
// get_entry() 함수, get_length() 함수 구현

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;

// 연결리스트의 노드 구조체
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

// 연결리스트 
typedef struct ListType {
	ListNode* head;
}ListType;

// 연결리스트 초기화
void init_list(ListType* list) {
	list->head = NULL;
}

int is_empty(ListType* list) {
	return(list->head == NULL);
}

void error(char* msg) {
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

void insert_first(ListType* list, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	// 노드 생성

	// 연결리스트가 비었을 경우
	if (is_empty(&list)) {
		list->head = p;
		p->data = value;
		p->link = NULL;
	}
	else {
		p->link = list->head;
		list->head = p;
		p->data = value;
		return;
	}
}

void print_list(ListType* list) {
	ListNode* p = list->head;
	
	while (p != NULL) {
		printf("%d -> ", p->data);
		p = p->link;
	}
	printf("NULL\n");
}

element get_entry(ListType* list, int index) {
	ListNode* p = list->head;
	int pos = 0;

	while (pos < index) {
		p = p->link;
		pos++;
	}
	return p->data;
}

int get_length(ListType* list) {
	ListNode* p = list->head;
	
	if (is_empty(&list))
		return 0;
	else {
		int cnt = 0;
		while (p != NULL) {
			p = p->link;
			cnt++;
		}
		return cnt;
	}
}

int main(void) {

	ListType *list1 = NULL;
	init_list(&list1);

	insert_first(&list1, 10);
	print_list(&list1);
	insert_first(&list1, 20);
	print_list(&list1);
	insert_first(&list1, 30);
	print_list(&list1);

	int length = get_length(&list1);
	printf("list1에 존재하는 노드의 총 갯수 : %d\n", length);

	for (int i = 0; i < length; i++)
		printf("list1의 %d번째 노드 데이터 : %d\n", i, get_entry(&list1, i));

	return 0;
}