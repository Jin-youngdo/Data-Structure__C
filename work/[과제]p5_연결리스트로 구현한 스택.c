// 11���� ���� 2 : p.5. ���Ḯ����� ������ ����
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct StackNode {  // ���� ���Ḯ��Ʈ ����ü
    element data;
    struct StackNode* link;
} StackNode;

typedef struct {            // ���Ḯ��Ʈ ������ ���� ���� ����ü
    StackNode* top;
} LinkedStackType;

// ���� �ʱ�ȭ �Լ�
void init(LinkedStackType* s) {
    s->top = NULL;
}
// ���� ���� ���� �Լ�
int is_empty(LinkedStackType* s) {
    return (s->top == NULL);
}
// ��ȭ ���� ���� �Լ�
int is_full(LinkedStackType* s) {
    return 0;
}

// ���� ���� �Լ�
void push(LinkedStackType* s, element item) {
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));

    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}

// ���� ���� �Լ�
element pop(LinkedStackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "������ �������\n");
        exit(1);
    }
    else {
        StackNode* temp = s->top;
        int data = temp->data;
        s->top = s->top->link;
        free(temp);
        return data;
    }
}

// ������ top�� �ִ� �����͸� ��ȯ�ϴ� �Լ�
element peek(LinkedStackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "������ �������\n");
        exit(1);
    }
    else
        return s->top->data;
}

// ���� ��� �Լ�
void print_stack(LinkedStackType* s) {
    StackNode* p;

    for (p = s->top; p != NULL; p = p->link) {
        printf(" %d -> ", p->data);
    }
    printf("NULL \n");
}

int main(void)
{
    LinkedStackType *s = (LinkedStackType*)malloc(sizeof(LinkedStackType));
    init(s);
    
    printf("�� ���� �߰� 3ȸ ���� ��\n");
    for (int i = 1; i <= 3; i++) {
        push(s, i); print_stack(s);
    }
        
    printf("\n�� ���� ���� 3ȸ ���� ��\n");
    for (int i = 0; i < 3; i++) {
        pop(s); print_stack(s);
    }
        
    free(s);
    return 0;
}