// p165 ���α׷� 5.4 : ���� ��(deque) ���α׷�
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
typedef int element;

// ťŸ�� ����
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

// ���� ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s \n", message);
	exit(1);
}

// ť �ʱ�ȭ �Լ�
// ����ť�� ���� ������ ����, front,rear 0���� �ʱ�ȭ
void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

// ��ȭ���� ���� �Լ�
int is_full(DequeType* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// ������� ���� �Լ�
int is_empty(DequeType* q) {
	return q->front == q->rear;
}

// ���� ť ��� �Լ�
void deque_print(DequeType* q) {
	printf("Deque[front : %d, rear : %d] => ", q->front, q->rear);

	if (!is_empty(q)) {
		int cnt = q->front;
		do {
			cnt = (cnt + 1) % MAX_QUEUE_SIZE;
			printf("%2d | ", q->data[cnt]);
			if (cnt == q->rear)
				break;
		} while (cnt != q->front);
	}
	else
		error("ť�� ��������Դϴ�.");

	printf("\n");
}

// �Ĵ� ���� �Լ�
void add_rear(DequeType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// �Ĵ� ���� �Լ�
element del_rear(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");

	int pre = q->rear;
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[pre];
}

// ���� ���� �Լ�
void add_front(DequeType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");

	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

// ���� ���� �Լ�
element del_front(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// front�� �����͸� ���� �Լ�(peek)
element get_front(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	
	return q->data[q->front + 1] % MAX_QUEUE_SIZE;
} 

// rear�� �����͸� ���� �Լ�(peek)
element get_rear(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");

	return q->data[q->rear];
}

void insert_front(DequeType *q, int count) {
	printf("front ���� ������ ���� %dȸ\n", count);
	
	int num = 0;
	for (int i = 0; i < count; i++) {
		add_front(q, num++);
		deque_print(q);
	} printf("\n");
}

void insert_rear(DequeType* q, int count) {
	printf("rear ���� ������ ���� %dȸ\n", count);

	int num = 0;
	for (int i = 0; i < count; i++) {
		add_rear(q, --num);
		deque_print(q);
	} printf("\n");
}

void delete_front(DequeType* q, int count) {
	printf("front ���� ������ ���� %dȸ\n", count);

	for (int i = 0; i < count; i++) {
		del_front(q);
		deque_print(q);
	} printf("\n");
}

void delete_rear(DequeType* q, int count) {
	printf("rear ���� ������ ���� %dȸ\n", count);

	for (int i = 0; i < count; i++) {
		del_rear(q);
		deque_print(q);
	} printf("\n");
}

int main(void) {

	DequeType queue;
	init_deque(&queue);

	// front ���� ���� 3ȸ ����
	insert_front(&queue, 3);

	// rear ���� ���� 3ȸ ����
	insert_rear(&queue, 3);

	// front ���� ���� 2ȸ ����
	delete_front(&queue, 2);

	// rear ���� ���� 4ȸ ����
	delete_rear(&queue, 4);

	return 0;

}