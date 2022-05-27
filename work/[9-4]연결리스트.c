// p197 프로그램 6.7 : 단순 연결 리스트
#include <stdio.h>
#include <stdlib.h>

typedef int element;

// 노드 구조체
typedef struct ListNode{
	element data;
	struct ListNode* link;	// 자기 참조
}ListNode;

void error(char* msg) {
	fprintf(stderr, "%s \n", msg);
	exit(1);
}

// 노드 삽입 함수
ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = head;	
	head = p;
	
	return head;
}

// 특정 위치에 노드를 삽입하는 함수
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = pre->link;
	pre->link = p;

	return head;
}

// 노드 제거 함수
ListNode* delete_first(ListNode* head) {
	ListNode* removed;

	if (head == NULL)
		return NULL;
	
	removed = head;		
	head = removed->link;	

	free(removed);		
	return head;
}

// 특정 위치의 노드를 제거하는 함수
ListNode* delete_node(ListNode* head, ListNode* pre) {
	ListNode* removed;

	removed = pre->link;
	pre->link = removed->link;

	free(removed);
	return head;
}

// 특정 위치 노드의 주소를 반환하는 함수
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

// 특정 위치의 노드가 가진 데이터를 반환하는 함수
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

// head 노드와 연결된 노드들의 data 출력 함수
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

	printf(" < insert_first 3회 수행 >\n\n");
	for (int i = 0; i < 3; i++) {
		head = insert_first(head, i);
		print_list(head);
	}

	printf("\n\n삽입할 노드의 위치(인덱스), 데이터 : ");
	scanf("%d %d", &index, &data);
	pre = get_loc(head, index);
	head = insert(head, pre, data);
	print_list(head);

	printf("\n\n< delete_first 4회 수행 > \n");
	for (int j = 0; j < 4; j++) {
		head = delete_first(head);
		print_list(head);
	}

	return 0;
}