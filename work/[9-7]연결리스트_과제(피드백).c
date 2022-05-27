#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;


void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode* head, int value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;

    return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;

    return head;
}

ListNode* delete_first(ListNode* head) {
    ListNode* removed;

    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete_list(ListNode* head, ListNode* pre) {
    ListNode* removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode* head) {
    ListNode* p;
    for (p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

element get_entry(ListNode* head, int index) {
    int i = 0;
    ListNode* p = head;
    while (p != NULL) {
        i++;
        if (i == index) return p->data;
        p = p->link;
    }
    return NULL;
}

element get_length(ListNode* head) {
    int i = 0;
    ListNode* p = head;
    while (p != NULL) {
        i++;
        p = p->link;
    }
    return i;
}

int main(void)
{
    int n, num, data;
    ListNode* head = NULL;

    head = insert_first(head, 10);
    head = insert_first(head, 20);
    head = insert_first(head, 30);
    head = insert_first(head, 40);
    print_list(head);
    num = get_length(head);
    printf("노드는 %d개 있습니다.\n", num);
    printf("몇번째 데이터? ");
    scanf("%d", &n);
    data = get_entry(head, n);
    printf("%d번째 데이터는 %d\n", n, data);

    for (int i = 0; i < 4; i++)
        head = delete_first(head);
    print_list(head);
    return 0;
}