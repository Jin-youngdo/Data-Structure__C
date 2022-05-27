// p161 : 큐 응용 버퍼 [개념만 알고있을것, 시험출제 x]
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS


// ======== 원형 큐 코드 ===========
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

// [포화상태] 검출
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// [공백상태] 검출
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
		error("큐가 포화 상태입니다.");

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // 원형 큐에서는 q->data[rear+1] 값을 push함
	q->data[q->rear] = item;
}

// pop() 
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백 상태입니다.");

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");

	return q->data[q->front + 1] % MAX_QUEUE_SIZE;
}



int main(void) {

	QueueType q;
	int data;

	init_queue(&q);

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		if (rand() % 5 == 0)	// 5로 나누어 떨어지면
			enqueue(&q, rand() % 100);
		queue_print(&q);

		if (rand() % 10 == 0)	// 10으로 나누어 떨어지면
			data = dequeue(&q);
		queue_print(&q);
	}

	return 0;
}