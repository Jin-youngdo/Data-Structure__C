// p.292 프로그램8.8 : 스레드 이진트리 순회 프로그램
#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;	// 스레드일시 TRUE
}TreeNode;

TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL, 1 };
TreeNode n3 = { 'C', &n1, &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 };
TreeNode n6 = { 'F', &n4, &n5, 0 };
TreeNode n7 = { 'G', &n3, &n6, 0 };
TreeNode* root = &n7;

TreeNode* find_successor(TreeNode* root) {
	// q는 p의 오른쪽 포인터
	TreeNode* q = root->right;

	// 만약 오른쪽 포인터가 NULL 이거나 스레드이면 오른쪽 포인터 반환
	if (q == NULL || root->is_thread == TRUE)
		return q;
	// 만약 오른쪽 자식이면 닥시 가장 왼쪽 노드로 이동
	while (q->left != NULL)
		q = q->left;
	return q;
}

void thread_inorder(TreeNode* root) {
	TreeNode* q = root;

	while (q->left)
		q = q->left;	// 가장 왼쪽 노드로 이동

	do {
		printf("%c -> ", q->data);
		q = find_successor(q);
	} while (q);
}

int main(void) {
	// 스레드 설정
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;

	// 중위 순회
	thread_inorder(root);
	printf("\n");
	return 0;
}