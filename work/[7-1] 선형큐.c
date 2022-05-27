// p150 : 선형 큐 프로그램
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

// ======== 선형 큐 코드 ======== 
typedef int element;				// int -> element형 선언
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {		// 큐의 초기화 rear,front -1로 초기화
	q->rear = -1;
	q->front = -1;
}

void queue_print(QueueType* q) {	// 큐의 삽입, 삭제 연산을 통한 진행과정 확인용
	int i;

	for (i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   |");
		else
			printf("%d |", q->data[i]);
	}
	printf("\n");
}

// q->rear == MAX_QUEUE_SIZE-1  →  q->rear가 -1인 상태의 초기값에서 시작, q->data[max_size-1]일 경우 
int is_full(QueueType* q) {			// 큐의 포화상태 검증
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

// q->front == q->rear  →  서로 -1인 초기 상태거나, 같은 횟수의 삽입, 삭제 연산 상태
int is_empty(QueueType* q) {		// 큐의 공백상태 검증
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType* q, int item) {	// 큐의 삽입 연산 == push()과 같은 역할
	if (is_full(q)) {					// 삽입 전 포화상태 검증
		error("큐가 포화 상태입니다.");
		exit(1); // return;
	}
	else
		q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q) {				// 큐의 제거 연산 == pop()과 같은 역할
	if (is_empty(q)) {					// 제거 전 공백상태 검증
		error("큐가 공백 상태입니다.");
		return -1;
	}
	else
		return q->data[++(q->front)];
}
// ======== 선형 큐 코드 종료 ======== 


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

	printf("\n현재 front : %d, rear : %d", q.front, q.rear);
	
	return 0;
}