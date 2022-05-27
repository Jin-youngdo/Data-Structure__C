// p234 : 이중 연결 리스트 예제
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* lLink;
	struct ListNode* rLink;
}ListNode;

// 이중 연결리스트 초기화
void init(ListNode* head) {
	head->lLink = head->rLink = head;
}

// 이중 연결리스트 노드 출력 함수
void print_list(ListNode* head) {
	ListNode* p;

	for (p = head->rLink; p != head; p = p->rLink)
		printf("<-| %d |-> ", p->data);
	printf("\n");
}

// 헤드 노드 앞에 노드를 삽입하는 함수
void Insert_node(ListNode* head, element value) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = value;
	newNode->lLink = head;
	newNode->rLink = head->rLink;
	head->rLink->lLink = newNode;
	head->rLink = newNode;
}

// 특정 노드의 주소를 전달받아 제거하는 함수
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

	printf(" < 헤드 노드의 앞에 노드 삽입 5회 > \n");
	for (int i = 0; i < 5; i++) {
		Insert_node(head, i);
		print_list(head);
	}

	printf("\n < 헤드 노드의 뒤 노드 삭제 5회 > \n");
	for (int i = 0; i < 5; i++) {
		print_list(head);
		delete_node(head, head->rLink);
	}
	
	free(head);
	return 0;
}