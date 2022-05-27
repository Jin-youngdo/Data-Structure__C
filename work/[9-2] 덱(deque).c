// p165 프로그램 5.4 : 원형 덱(deque) 프로그램
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10
typedef int element;

// 큐타입 지정
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

// 오류 검증 함수
void error(char* message) {
	fprintf(stderr, "%s \n", message);
	exit(1);
}

// 큐 초기화 함수
// 원형큐와 같은 구조로 구성, front,rear 0으로 초기화
void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

// 포화상태 검증 함수
int is_full(DequeType* q) {
	return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

// 공백상태 검증 함수
int is_empty(DequeType* q) {
	return q->front == q->rear;
}

// 원형 큐 출력 함수
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
		error("큐가 공백상태입니다.");

	printf("\n");
}

// 후단 삽입 함수
void add_rear(DequeType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 후단 제거 함수
element del_rear(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");

	int pre = q->rear;
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[pre];
}

// 전단 삽입 함수
void add_front(DequeType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");

	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

// 전단 제거 함수
element del_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// front의 데이터를 보는 함수(peek)
element get_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	
	return q->data[q->front + 1] % MAX_QUEUE_SIZE;
} 

// rear의 데이터를 보는 함수(peek)
element get_rear(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");

	return q->data[q->rear];
}

void insert_front(DequeType *q, int count) {
	printf("front 방향 데이터 삽입 %d회\n", count);
	
	int num = 0;
	for (int i = 0; i < count; i++) {
		add_front(q, num++);
		deque_print(q);
	} printf("\n");
}

void insert_rear(DequeType* q, int count) {
	printf("rear 방향 데이터 삽입 %d회\n", count);

	int num = 0;
	for (int i = 0; i < count; i++) {
		add_rear(q, --num);
		deque_print(q);
	} printf("\n");
}

void delete_front(DequeType* q, int count) {
	printf("front 방향 데이터 삭제 %d회\n", count);

	for (int i = 0; i < count; i++) {
		del_front(q);
		deque_print(q);
	} printf("\n");
}

void delete_rear(DequeType* q, int count) {
	printf("rear 방향 데이터 삭제 %d회\n", count);

	for (int i = 0; i < count; i++) {
		del_rear(q);
		deque_print(q);
	} printf("\n");
}

int main(void) {

	DequeType queue;
	init_deque(&queue);

	// front 방향 삽입 3회 수행
	insert_front(&queue, 3);

	// rear 방향 삽입 3회 수행
	insert_rear(&queue, 3);

	// front 방향 삭제 2회 수행
	delete_front(&queue, 2);

	// rear 방향 삭제 4회 수행
	delete_rear(&queue, 4);

	return 0;

}