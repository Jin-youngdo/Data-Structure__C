// 11���� ���� 3 : p7. ���Ḯ��Ʈ�� ������ ť
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct QueueNode {  // ���� ���Ḯ��Ʈ ����ü
    element data;
    struct QueueNode* link;
} QueueNode;

typedef struct {            // ���Ḯ��Ʈ ������ ���� ť ����ü
    QueueNode* front, * rear;
} LinkedQueueType;

// ť �ʱ�ȭ �Լ�
void init(LinkedQueueType* q) {
    q->front = q->rear = NULL;
}

// ������� ���� �Լ�
int is_empty(LinkedQueueType* q) {
    return (q->front == NULL);
}

// ��ȭ���� ���� �Լ�
int is_full(LinkedQueueType* q) {
    return 0;
}

// ť ���� �Լ�
void enqueue(LinkedQueueType* q, element data) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));

    temp->data = data;
    temp->link = NULL;
    if (is_empty(q)) { // ť�� ������ ���(q->front == NULL)
        q->front = temp;
        q->rear = temp;
    }
    else {  // ť�� ������ �ƴҰ��
        q->rear->link = temp;
        q->rear = temp;
    }
}

// ť ���� �Լ�
element dequeue(LinkedQueueType* q) {
    QueueNode* temp = q->front;
    element data;
    if (is_empty(q)) {		// �������
        fprintf(stderr, "������ �������\n");
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

    printf("�� ť �߰� 3ȸ ���� ��\n");
    for (int i = 1; i < 4; i++) {
        enqueue(queue, i); print_queue(queue);
    }
        
    printf("\n�� ť ���� 3ȸ ���� ��\n");
    for (int i = 0; i < 3; i++) {
        dequeue(queue); print_queue(queue);
    }

    free(queue);
    return 0;
}