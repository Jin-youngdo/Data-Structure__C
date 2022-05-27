// p160 : Quiz_2 ���� ť ����
#include <stdio.h>
#include <stdlib.h>

// ======== ���� ť �ڵ� ===========
#define MAX_QUEUE_SIZE 10
typedef char element;
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
	printf("QUEUE(front = %d  rear = %d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%c | ", q->data[i]);

			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

int main(void) {

	QueueType q;
	init_queue(&q);

	enQueue(&q, 'a'); queue_print(&q);
	enQueue(&q, 'b'); queue_print(&q);
	enQueue(&q, 'c'); queue_print(&q);

	deQueue(&q); queue_print(&q);

	enQueue(&q, 'd'); queue_print(&q);

	printf("\n���� ���� ť q�� front=%d,  rear=%d\n", q.front, q.rear);

	return 0;
}