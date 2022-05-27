// p.286 프로그램 8.7 : 디렉토리 용량 계산 프로그램
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

// 재귀 함수 구현
int calc_dir_size1(TreeNode* root) {
	int left_size, right_size;
	if (root == NULL)
		return 0;

	left_size = calc_dir_size1(root->left);
	right_size = calc_dir_size1(root->right);
	return (root->data + left_size + right_size);
}

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p) {
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode* pop() {
	TreeNode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

// 반복문 함수 구현
int calc_dir_size2(TreeNode* root) {
	int size=0;
	if (root == NULL)
		return 0;

	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();
		if (!root)
			break;
		size += root->data;
		root = root->right;
	}
	return size;
}
/*
            0
      50         100
   150        500   200
*/

int main(void) {

	TreeNode n1 = { 150, NULL, NULL };
	TreeNode n2 = { 50, &n1, NULL };
	TreeNode n3 = { 500, NULL, NULL };
	TreeNode n4 = { 200, NULL, NULL };
	TreeNode n5 = { 100, &n3, &n4 };
	TreeNode n6 = { 0, &n2, &n5 };

	int dir_size = calc_dir_size1(&n6);
	printf("[재귀 함수]총 디렉토리의 크기 = %dKB\n", dir_size);

	dir_size = calc_dir_size2(&n6);
	printf("[반복문 함수]총 디렉토리의 크기 = %dKB\n", dir_size);

	return 0;
}