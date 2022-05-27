// 피드백 - 이중연결리스트 - 탐색, 삽입, 삭제
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}
void print_dlist(DListNode* phead) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("<-%d->", p->data);
    }
    printf("\n");
}

void dinsert(DListNode* before, element data) {
    DListNode* newnode =
        (DListNode*)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed) {
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

DListNode* search(DListNode* head, element data) {
    DListNode* p;
    
    for (p = head->rlink; p != head; p = p->rlink) {
        if (p->data == data)
            return p;
    }
    return NULL;
}

int main(void)
{
    int i;
    DListNode* head =
        (DListNode*)malloc(sizeof(DListNode));
    init(head);
    DListNode* find = NULL;

    dinsert(head, 10);
    dinsert(head, 20);
    dinsert(head, 30);
    dinsert(head, 40);
    print_dlist(head);

    find = search(head, 30);
    dinsert(find, 35);
    print_dlist(head);

    find = search(head, 35);
    ddelete(head, find);
    print_dlist(head);
    
    ddelete(head, head->llink);
    print_dlist(head);


    free(head);
    return 0;
}