// p150 : ���� ť ���α׷�
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

// ======== ���� ť �ڵ� ======== 
typedef int element;				// int -> element�� ����
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {		// ť�� �ʱ�ȭ rear,front -1�� �ʱ�ȭ
	q->rear = -1;
	q->front = -1;
}

void queue_print(QueueType* q) {	// ť�� ����, ���� ������ ���� ������� Ȯ�ο�
	int i;

	for (i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   |");
		else
			printf("%d |", q->data[i]);
	}
	printf("\n");
}

// q->rear == MAX_QUEUE_SIZE-1  ��  q->rear�� -1�� ������ �ʱⰪ���� ����, q->data[max_size-1]�� ��� 
int is_full(QueueType* q) {			// ť�� ��ȭ���� ����
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

// q->front == q->rear  ��  ���� -1�� �ʱ� ���°ų�, ���� Ƚ���� ����, ���� ���� ����
int is_empty(QueueType* q) {		// ť�� ������� ����
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType* q, int item) {	// ť�� ���� ���� == push()�� ���� ����
	if (is_full(q)) {					// ���� �� ��ȭ���� ����
		error("ť�� ��ȭ �����Դϴ�.");
		exit(1); // return;
	}
	else
		q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q) {				// ť�� ���� ���� == pop()�� ���� ����
	if (is_empty(q)) {					// ���� �� ������� ����
		error("ť�� ���� �����Դϴ�.");
		return -1;
	}
	else
		return q->data[++(q->front)];
}
// ======== ���� ť �ڵ� ���� ======== 


int main(void) {

	int item;
	QueueType q;
	
	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);
	enqueue(&q, 40); queue_print(&q);
	enqueue(&q, 50); queue_print(&q);

	printf("\n");

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	/*item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);*/

	printf("\n���� front : %d, rear : %d", q.front, q.rear);
	
	return 0;
}