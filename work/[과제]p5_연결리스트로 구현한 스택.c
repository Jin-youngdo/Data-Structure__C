// 11주차 과제 2 : p.5. 연결리스토로 구현한 스택
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct StackNode {  // 단일 연결리스트 구조체
    element data;
    struct StackNode* link;
} StackNode;

typedef struct {            // 연결리스트 구조를 가진 스택 구조체
    StackNode* top;
} LinkedStackType;

// 스택 초기화 함수
void init(LinkedStackType* s) {
    s->top = NULL;
}
// 공백 상태 검증 함수
int is_empty(LinkedStackType* s) {
    return (s->top == NULL);
}
// 포화 상태 검증 함수
int is_full(LinkedStackType* s) {
    return 0;
}

// 스택 삽입 함수
void push(LinkedStackType* s, element item) {
    StackNode* temp = (StackNode*)malloc(sizeof(StackNode));

    temp->data = item;
    temp->link = s->top;
    s->top = temp;
}

// 스택 삭제 함수
element pop(LinkedStackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
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

// 스택의 top에 있는 데이터를 반환하는 함수
element peek(LinkedStackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else
        return s->top->data;
}

// 스택 출력 함수
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
    
    printf("《 스택 추가 3회 수행 》\n");
    for (int i = 1; i <= 3; i++) {
        push(s, i); print_stack(s);
    }
        
    printf("\n《 스택 삭제 3회 수행 》\n");
    for (int i = 0; i < 3; i++) {
        pop(s); print_stack(s);
    }
        
    free(s);
    return 0;
}