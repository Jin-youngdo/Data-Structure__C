// p161 : ť ���� ���� [���丸 �˰�������, �������� x]
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS


// ======== ���� ť �ڵ� ===========
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}

// [��ȭ����] ����
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// [�������] ����
int is_empty(QueueType* q) {

	return(q->front == q->rear);
}

void queue_print(QueueType* q) {
	printf("QUEUE(front = %d  rear = %d) = ", q->front, q->rear);
	if (is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);

			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}


// push()
void enqueue(QueueType* q, int item) {
	if (is_full(q))
		error("ť�� ��ȭ �����Դϴ�.");

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // ���� ť������ q->data[rear+1] ���� push��
	q->data[q->rear] = item;
}

// pop() 
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ���� �����Դϴ�.");

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");

	return q->data[q->front + 1] % MAX_QUEUE_SIZE;
}



int main(void) {

	QueueType q;
	int data;

	init_queue(&q);

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		if (rand() % 5 == 0)	// 5�� ������ ��������
			enqueue(&q, rand() % 100);
		queue_print(&q);

		if (rand() % 10 == 0)	// 10���� ������ ��������
			data = dequeue(&q);
		queue_print(&q);
	}

	return 0;
}