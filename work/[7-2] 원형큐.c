// p157 : ���� ť ���α׷�
#include <stdio.h>
#include <stdlib.h>
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

void init_queue(QueueType* q) {		// ���� ť�� �ٸ��� rear, front 0���� �ʱ�ȭ
	q->rear = 0;
	q->front = 0;
}

int is_empty(QueueType* q) {		// ������� ����
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

int is_full(QueueType* q) {			// ��ȭ���� ����
	if (q->front == (q->rear + 1) % MAX_QUEUE_SIZE)
		return 1;
	else
		return 0;
}

void enQueue(QueueType* q, element item) {	// ���� ť�� ���� ����
	if (is_full(q)) 
		error("ť�� ��ȭ �����Դϴ�.");
	
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // ���� ť������ q->data[rear+1] ���� push�� 
	q->data[q->rear] = item;				  // enQueue()�� rear�� �ʱⰪ�� ��ǻ� 1 
}

element deQueue(QueueType* q) {				// ���� ť�� ���� ����
	if (is_empty(q))
		error("ť�� ���� �����Դϴ�.");

	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // ���� ť������ q->data[front+1] ���� pop�� 
	return q->data[q->front];				    // deQueue()�� front�� �ʱⰪ�� ��ǻ� 1 
}

element peek(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");

	return q->data[q->front + 1] % MAX_QUEUE_SIZE;
}

void queue_print(QueueType* q) {	// ����ť ���
	printf("QUEUE(front = %d   rear = %d) = ", q->front, q->rear);
	if (!is_empty(q)) {
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

// ======== ���� ť �ڵ� ���� ===========

int main(void) {

	QueueType q;
	int element;

	init_queue(&q);


	printf("---������ �߰� �ܰ�---\n");
	while (!is_full(&q)) {
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &element);
		enQueue(&q, element);
		queue_print(&q);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");


	printf("---������ ���� �ܰ�---\n");
	while (!is_empty(&q)) {
		element = deQueue(&q);
		printf("������ ���� : %d \n", element);
		queue_print(&q);
	}

	printf("ť�� ��������Դϴ�.\n");

	printf("���� ť�� �迭 %d %d %d %d %d\n", q.data[0], q.data[1], q.data[2], q.data[3], q.data[4]);

	return 0;
}