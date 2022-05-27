// p182 프로그램 6.1 : 배열로 리스트 구조 구현
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

void error(char *msg){
	fprintf(stderr, "%s \n", msg);
	exit(1);
}

void init(ArrayListType* L) {		// 리스트 초기화 함수
	L->size = 0;
}

int is_empty(ArrayListType* L) {	// 리스트 공백상태 검사 
	return L->size == 0;
}

int is_full(ArrayListType* L) {		// 리스트 포화상태 검사
	return L->size == MAX_LIST_SIZE;
}

// 리스트의 pos 위치에 있는 값 반환 함수
element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}

void print_list(ArrayListType* L) {	// 리스트 출력 함수
	for (int i = 0; i < L->size; i++)
		printf("%d -> ", L->array[i]);
	printf("\n");
}

// 리스트의 맨 끝에 item 삽입 함수
void insert_last(ArrayListType* L, element item) {
	if (L->size >= MAX_LIST_SIZE)
		error("리스트 오버플로우");
	L->array[L->size++] = item;
}

// 리스트의 pos 위치에 item 삽입
void insert(ArrayListType* L, int pos, element item) {
	
	if (!is_full(&L) && (L->size <= pos >= 0)) {
		// 리스트의 pos 위치에 item을 삽입하기 위해 
		// pos 위치 이후의 인덱스 값들 오른쪽으로 이동
		for (int i = L->size - 1; i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}

// 리스트의 pos 위치의 데이터 삭제
void delete_list(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("위치 오류");

	// insert() 함수와 반대로 pos 위치 이후의 인덱스 값들을
	// pos 위치가 될때까지 왼쪽으로 이동
	for (int i = pos; i < L->size - 1; i++)
		L->array[i] = L->array[i + 1];
	L->size--;

}

int main(void) {

	ArrayListType list;
	init(&list);

	for (int i = 10; i <= 40; i = i + 10) {
		insert_last(&list, i);
		print_list(&list);
	} printf("\n");

	printf("< list의 1번째 인덱스에 15 삽입 >\n");
	insert(&list, 1, 15);
	print_list(&list);
	printf("\n");

	printf("< list의 4번째 인덱스 값 제거 >\n");
	delete_list(&list, 4);
	print_list(&list);

	return 0;
}