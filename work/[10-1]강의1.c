// 연결 리스트의 중간 노드에 삽입, 특정 데이터 삭제 함수 
#include <stdio.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

// 첫번째 노드 위치에 노드를 삽입하는 함수
ListNode* insert_first(ListNode* head, int value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));

    p->data = value;
    p->link = head;
    head = p;
    return head;
}

// 특정 노드의 뒤에 노드를 삽입하는 함수
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));

    p->data = value;
    p->link = pre->link;
    pre->link = p;

    return head;
}

// 첫번째 노드를 삭제하는 함수
ListNode* delete_first(ListNode* head) {
    ListNode* removed = head;

    head = removed->link;
    free(removed);
    printf("\n첫번째 데이터 삭제\n");
    return head;
}

// 특정 노드 뒤의 노드를 삭제하는 함수
ListNode* delete_node(ListNode* head, ListNode* pre) {
    ListNode* removed = pre->link;

    pre->link = removed->link;
    free(removed);
    return head;
}

// 노드의 길이를 구하는 함수
element get_length(ListNode* head) {
    int count = 0;
    ListNode* p = head;
    while (p != NULL) {
        count++;
        p = p->link;
    }
    return count;
}

// 특정 위치 노드의 데이터값을 반환하는 함수
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

// 특정 위치 노드의 주소를 반환하는 함수
ListNode* get_loc(ListNode* head, int index) {
    ListNode* p = head;

    for (int i = 1; i < index; i++)
        p = p->link;
    return p;
}

// 특정 값을 가진 노드의 주소를 반환하는 함수
ListNode* get_node(ListNode* head, element data) {

    while (head != NULL) {
        if (head->data == data)
            return head;
        head = head->link;
    }
    return NULL;
}

// 특정 노드 앞의 노드를 반환하는 함수
ListNode* get_preNode(ListNode* head, ListNode* node) {
    ListNode* pre = head;

    int h_len = get_length(head);
    int n_len = get_length(node);

    for (int i = h_len; i > n_len + 1; i--)
        pre = pre->link;

    return pre;
}

// 노드 출력 함수
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
    printf("노드는 %d개 있습니다.\n", len);

    printf("\n몇번째 데이터를 탐색하시겠습니까? (MAX : %d) ", len);
    scanf("%d", &index);
    data = get_entry(head, index);      // get_entry() : 특정 위치 노드의 데이터값 반환 함수 
    printf("%d번째 데이터는 %d\n", index, data);

    printf("\n몇번째 노드의 주소 선택? (MIN: 2, MAX : %d) ", len);
    scanf("%d", &index);
    // insert()함수는 특정 노드 위치의 뒤로 노드를 삽입하기에 
    // 이를 위해 n_loc노드 앞의 노드인 pre노드를 사용 (index의 최소값이 2일수밖에 없음)
    n_loc = get_loc(head, index);       // get_loc()를 통해 index번째 데이터 주소 반환
    pre = get_preNode(head, n_loc);     // get_preNode()를 통해 n_loc 노드 앞의 노드 반환

    printf("\n%d번째 노드의 위치에 삽입할 데이터 : ", index);
    scanf("%d", &data);
    head = insert(head, pre, data);     // 결과적으로 n_loc 노드의 위치에 data가 담긴 노드 삽입
    print_list(head);

    printf("\n삭제할 데이터 : ");
    scanf("%d", &del_data);

    n_loc = get_node(head, del_data);   // get_node()를 통해 del_data를 가진 노드 주소 반환
    pre = get_preNode(head, n_loc);     // get_preNode()를 통해 n_loc 노드 앞의 노드 반환
    head = delete_node(head, pre);      // delete_node()를 통해 pre노드 뒤의 노드(n_loc) 삭제
    // 결과적으로 n_loc 주소를 삭제하게 된다.
    print_list(head);

    head = delete_first(head);
    print_list(head);

    return 0;
}