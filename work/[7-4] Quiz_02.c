// p160 : Quiz_2 원형 큐 예제
#include <stdio.h>
#include <stdlib.h>

// ======== 원형 큐 코드 ===========
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

void init_queue(QueueType* q) {		// 선형 큐와 다르게 rear, front 0으로 초기화
	q->rear = 0;
	q->front = 0;
}

int is_empty(QueueType* q) {		// 공백상태 검증
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

int is_full(QueueType* q) {			// 포화상태 검증
	if (q->front == (q->rear + 1) % MAX_QUEUE_SIZE)
		return 1;
	else
		return 0;
}

void enQueue(QueueType* q, element item) {	// 원형 큐의 삽입 연산
	if (is_full(q))
		error("큐가 포화 상태입니다.");

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // 원형 큐에서는 q->data[rear+1] 값을 push함 
	q->data[q->rear] = item;				  // enQueue()시 rear의 초기값은 사실상 1 
}

element deQueue(QueueType* q) {				// 원형 큐의 삭제 연산
	if (is_empty(q))
		error("큐가 공백 상태입니다.");

	q->front = (q->front + 1) % MAX_QUEUE_SIZE; // 원형 큐에서는 q->data[front+1] 값을 pop함 
	return q->data[q->front];				    // deQueue()시 front의 초기값은 사실상 1 
}

element peek(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");

	return q->data[q->front + 1] % MAX_QUEUE_SIZE;
}

void queue_print(QueueType* q) {	// 원형큐 출력
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

	printf("\n현재 원형 큐 q의 front=%d,  rear=%d\n", q.front, q.rear);

	return 0;
}