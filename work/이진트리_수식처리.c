// 이진트리 수식처리(후위 순회)
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

// 루트 노드 및 서브 트리 정의
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  NULL,  NULL };
TreeNode n3 = { '*', &n1, &n2};
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4, &n5};
TreeNode n7 = { '+', &n3, &n6 };
TreeNode* root = &n7;

int evaluate(TreeNode* root) {
	int cnt = 0;
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)	// 리프 노드인 경우(피연산자)
		return root->data;
	else {	// 내부 노드인 경우(연산자)
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf(" %2d %c %2d를 계산\n", op1, root->data, op2);

		switch (root->data) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		}
	}
	return 0;
}

int main(void) {

	printf("\n 수식의 값은 %d입니다\n", evaluate(root));
	return 0;
}