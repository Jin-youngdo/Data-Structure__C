// p.310 Ʈ���� ���� ���ϱ�, ��� Ž�� Ƚ�� ��� ��� [����]
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(a, b) ( a>b ? a:b )
#define _CRT_NO_SECURE_WARNINGS

typedef int element;	// element �ڷ��� ����
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// ����Ž��Ʈ�� Ű���� ���޹޾� ��� ������ ��ȯ �Լ�
TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));

	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// ����Ž��Ʈ�� ���� �Լ�
TreeNode* insert_node(TreeNode* node, element key) {
	if (node == NULL)
		return new_node(key);

	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}

// ����� ���̸� ���ϴ� �Լ�
int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

// ��� �˻� Ƚ�� ��� �Լ�
double get_search_avg(TreeNode* node) {
	int height = get_height(node);		// 6 -> 2
	double result = log2(height);
	return result;
}

int main(void) {
	TreeNode* root = NULL;

	root = insert_node(root, 7);
	root = insert_node(root, 1);
	root = insert_node(root, 9);
	root = insert_node(root, 5);
	root = insert_node(root, 8);
	root = insert_node(root, 2);
	root = insert_node(root, 3);
	root = insert_node(root, 4);
	root = insert_node(root, 6);
	//                 Ʈ�� 
	//                  7
	//             1         9
	//               5          8 
	//            2     6
	//               3 
	//                 4
	printf("Ʈ���� ����(h) : %d\n", get_height(root));
	printf("Ʈ�� ��� �˻� Ƚ��(log��h) : %lf\n", get_search_avg(root));
	return 0;
}