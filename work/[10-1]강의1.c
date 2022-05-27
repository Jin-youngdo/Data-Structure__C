// ���� ����Ʈ�� �߰� ��忡 ����, Ư�� ������ ���� �Լ� 
#include <stdio.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

// ù��° ��� ��ġ�� ��带 �����ϴ� �Լ�
ListNode* insert_first(ListNode* head, int value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));

    p->data = value;
    p->link = head;
    head = p;
    return head;
}

// Ư�� ����� �ڿ� ��带 �����ϴ� �Լ�
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));

    p->data = value;
    p->link = pre->link;
    pre->link = p;

    return head;
}

// ù��° ��带 �����ϴ� �Լ�
ListNode* delete_first(ListNode* head) {
    ListNode* removed = head;

    head = removed->link;
    free(removed);
    printf("\nù��° ������ ����\n");
    return head;
}

// Ư�� ��� ���� ��带 �����ϴ� �Լ�
ListNode* delete_node(ListNode* head, ListNode* pre) {
    ListNode* removed = pre->link;

    pre->link = removed->link;
    free(removed);
    return head;
}

// ����� ���̸� ���ϴ� �Լ�
element get_length(ListNode* head) {
    int count = 0;
    ListNode* p = head;
    while (p != NULL) {
        count++;
        p = p->link;
    }
    return count;
}

// Ư�� ��ġ ����� �����Ͱ��� ��ȯ�ϴ� �Լ�
element get_entry(ListNode* head, int index) {
    int i = 0;
    ListNode* p = head;

    while (p != NULL) {
        i++;
        if (i == index)
            return p->data;
        p = p->link;
    }
    return NULL;
}

// Ư�� ��ġ ����� �ּҸ� ��ȯ�ϴ� �Լ�
ListNode* get_loc(ListNode* head, int index) {
    ListNode* p = head;

    for (int i = 1; i < index; i++)
        p = p->link;
    return p;
}

// Ư�� ���� ���� ����� �ּҸ� ��ȯ�ϴ� �Լ�
ListNode* get_node(ListNode* head, element data) {

    while (head != NULL) {
        if (head->data == data)
            return head;
        head = head->link;
    }
    return NULL;
}

// Ư�� ��� ���� ��带 ��ȯ�ϴ� �Լ�
ListNode* get_preNode(ListNode* head, ListNode* node) {
    ListNode* pre = head;

    int h_len = get_length(head);
    int n_len = get_length(node);

    for (int i = h_len; i > n_len + 1; i--)
        pre = pre->link;

    return pre;
}

// ��� ��� �Լ�
void print_list(ListNode* head) {
    ListNode* p;

    for (p = head; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    printf("NULL \n");
}

int main(void)
{
    int index, data, del_data;
    ListNode* head = NULL;
    ListNode* pre = NULL;
    ListNode* n_loc = NULL;

    for (int i = 10; i <= 40; i = i + 10) {
        head = insert_first(head, i);
    }
    int len = get_length(head);
    print_list(head);
    printf("���� %d�� �ֽ��ϴ�.\n", len);

    printf("\n���° �����͸� Ž���Ͻðڽ��ϱ�? (MAX : %d) ", len);
    scanf("%d", &index);
    data = get_entry(head, index);      // get_entry() : Ư�� ��ġ ����� �����Ͱ� ��ȯ �Լ� 
    printf("%d��° �����ʹ� %d\n", index, data);

    printf("\n���° ����� �ּ� ����? (MIN: 2, MAX : %d) ", len);
    scanf("%d", &index);
    // insert()�Լ��� Ư�� ��� ��ġ�� �ڷ� ��带 �����ϱ⿡ 
    // �̸� ���� n_loc��� ���� ����� pre��带 ��� (index�� �ּҰ��� 2�ϼ��ۿ� ����)
    n_loc = get_loc(head, index);       // get_loc()�� ���� index��° ������ �ּ� ��ȯ
    pre = get_preNode(head, n_loc);     // get_preNode()�� ���� n_loc ��� ���� ��� ��ȯ

    printf("\n%d��° ����� ��ġ�� ������ ������ : ", index);
    scanf("%d", &data);
    head = insert(head, pre, data);     // ��������� n_loc ����� ��ġ�� data�� ��� ��� ����
    print_list(head);

    printf("\n������ ������ : ");
    scanf("%d", &del_data);

    n_loc = get_node(head, del_data);   // get_node()�� ���� del_data�� ���� ��� �ּ� ��ȯ
    pre = get_preNode(head, n_loc);     // get_preNode()�� ���� n_loc ��� ���� ��� ��ȯ
    head = delete_node(head, pre);      // delete_node()�� ���� pre��� ���� ���(n_loc) ����
    // ��������� n_loc �ּҸ� �����ϰ� �ȴ�.
    print_list(head);

    head = delete_first(head);
    print_list(head);

    return 0;
}