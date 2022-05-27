// p182 ���α׷� 6.1 : �迭�� ����Ʈ ���� ����
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

void init(ArrayListType* L) {		// ����Ʈ �ʱ�ȭ �Լ�
	L->size = 0;
}

int is_empty(ArrayListType* L) {	// ����Ʈ ������� �˻� 
	return L->size == 0;
}

int is_full(ArrayListType* L) {		// ����Ʈ ��ȭ���� �˻�
	return L->size == MAX_LIST_SIZE;
}

// ����Ʈ�� pos ��ġ�� �ִ� �� ��ȯ �Լ�
element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	return L->array[pos];
}

void print_list(ArrayListType* L) {	// ����Ʈ ��� �Լ�
	for (int i = 0; i < L->size; i++)
		printf("%d -> ", L->array[i]);
	printf("\n");
}

// ����Ʈ�� �� ���� item ���� �Լ�
void insert_last(ArrayListType* L, element item) {
	if (L->size >= MAX_LIST_SIZE)
		error("����Ʈ �����÷ο�");
	L->array[L->size++] = item;
}

// ����Ʈ�� pos ��ġ�� item ����
void insert(ArrayListType* L, int pos, element item) {
	
	if (!is_full(&L) && (L->size <= pos >= 0)) {
		// ����Ʈ�� pos ��ġ�� item�� �����ϱ� ���� 
		// pos ��ġ ������ �ε��� ���� ���������� �̵�
		for (int i = L->size - 1; i >= pos; i--)
			L->array[i + 1] = L->array[i];
		L->array[pos] = item;
		L->size++;
	}
}

// ����Ʈ�� pos ��ġ�� ������ ����
void delete_list(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");

	// insert() �Լ��� �ݴ�� pos ��ġ ������ �ε��� ������
	// pos ��ġ�� �ɶ����� �������� �̵�
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

	printf("< list�� 1��° �ε����� 15 ���� >\n");
	insert(&list, 1, 15);
	print_list(&list);
	printf("\n");

	printf("< list�� 4��° �ε��� �� ���� >\n");
	delete_list(&list, 4);
	print_list(&list);

	return 0;
}