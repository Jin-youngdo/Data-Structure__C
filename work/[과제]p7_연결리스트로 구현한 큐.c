// 11주차 과제 3 : p7. 연결리스트로 구현한 큐
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct QueueNode {  // 단일 연결리스트 구조체
    element data;
    struct QueueNode* link;
} QueueNode;

typedef struct {            // 연결리스트 구조를 가진 큐 구조체
    QueueNode* front, * rear;
} LinkedQueueType;

// 큐 초기화 함수
void init(LinkedQueueType* q) {
    q->front = q->rear = NULL;
}

// 공백상태 검증 함수
int is_empty(LinkedQueueType* q) {
    return (q->front == NULL);
}

// 포화상태 검증 함수
int is_full(LinkedQueueType* q) {
    return 0;
}

// 큐 삽입 함수
void enqueue(LinkedQueueType* q, element data) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));

    temp->data = data;
    temp->link = NULL;
    if (is_empty(q)) { // 큐가 공백일 경우(q->front == NULL)
        q->front = temp;
        q->rear = temp;
    }
    else {  // 큐가 공백이 아닐경우
        q->rear->link = temp;
        q->rear = temp;
    }
}

// 큐 제거 함수
element dequeue(LinkedQueueType* q) {
    QueueNode* temp = q->front;
    element data;
    if (is_empty(q)) {		// 공백상태
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else {
        data = temp->data;
        q->front = q->front->link;
        if (q->front == NULL)
            q->rear = NULL;
        free(temp);
        return data;
    }
}

void print_queue(LinkedQueueType* q) {
    QueueNode* p;
    for (p = q->front; p != NULL; p = p->link)
        printf(" %d -> ", p->data);
    printf("NULL\n");
}

int main(void)
{
    LinkedQueueType *queue = (LinkedQueueType*)malloc(sizeof(LinkedQueueType));
    init(queue);

    printf("《 큐 추가 3회 수행 》\n");
    for (int i = 1; i < 4; i++) {
        enqueue(queue, i); print_queue(queue);
    }
        
    printf("\n《 큐 삭제 3회 수행 》\n");
    for (int i = 0; i < 3; i++) {
        dequeue(queue); print_queue(queue);
    }

    free(queue);
    return 0;
}