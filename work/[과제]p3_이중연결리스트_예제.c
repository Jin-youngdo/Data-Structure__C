// 11주차 과제 1 : p3. 이중 연결리스트 - 삽입, 삭제
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// 헤드 노드 초기화 함수
void init(DListNode* phead) {
	phead->llink = phead->rlink = phead;
}

// 이중 연결리스트 출력 함수
void print_dList(DListNode *phead) {
	DListNode* p;

	for (p = phead->rlink; p != phead; p = p->rlink)
		printf("<-%d-> ", p->data);
	printf("\n");
}

// 노드의 뒤에 노드를 삽입하는 함수
void dinsert(DListNode* before, element value) {
	DListNode* p = (DListNode*)malloc(sizeof(DListNode));

	p->data = value;
	p->llink = before;
	p->rlink = before->rlink;

	before->rlink->llink = p;
	before->rlink = p;
}

// 헤드 노드와 연결된 노드의 주소를 전달받아 제거하는 함수
void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head)
		return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

// 특정 값을 가진 노드의 주소를 반환하는 함수
DListNode* search(DListNode* head, element value) {
	DListNode* p;

	for (p = head->rlink; p != head; p=p->rlink)
		if (p->data == value)
			return p;
	return NULL;
}

int main(void) {

	DListNode* head = (DListNode*)malloc(sizeof(DListNode));	// 헤드 노드 생성
	init(head);	// 헤드 노드 초기화
	DListNode* find = NULL;	// 탐색할 임시 노드 생성

	for (int i = 10; i <= 40; i = i + 10)
		dinsert(head, i);
	printf("《 dinsert() 4회 수행 》\n");
	print_dList(head);

	find = search(head, 30);	// 이중 연결리스트 내 data==30인 노드의 주소를 find에 저장
	dinsert(find, 35);			// find의 주소의 뒤에 data==35인 노드를 삽입
	printf("\n《 이중 연결리스트의 data==30인 노드의 뒤에 data==35인 노드 삽입 》\n");
	print_dList(head);

	find = search(head, 35);	// 이중 연결리스트 내 data==35인 노드의 주소를 find에 저장
	ddelete(head, find);		// head노드와 연결된 data==35인 find 노드를 삭제
	printf("\n《 이중 연결리스트의 data==35인 노드 삭제 》\n");
	print_dList(head);

	ddelete(head, head->rlink);	// 헤드 노드 뒤의 노드 삭제
	printf("\n《 이중 연결리스트의 헤드노드 뒤의 노드 삭제 》\n");
	print_dList(head);

	free(head);	// head 노드 동적 메모리 반환
	return 0;
}