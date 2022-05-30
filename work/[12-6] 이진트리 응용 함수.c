// p.290 이진트리의 노드 개수, 단말 노드 개수 , 높이 구하기 [과제]
#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) ( x>y ? x:y )

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// 이진트리의 총 노드 개수를 반환하는 함수
int get_node_count(TreeNode* node) {
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}

// 이진트리의 단말노드 개수를 반환하는 함수
int get_leaf_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		// 현재 노드가 단말 노드인 경우 1 반환
		if (node->left == NULL && node->right == NULL)
			return 1;
		// 현재 노드가 비단말 노드일 경우(자식이 하나라도 있을 경우)
		else
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
	}
	return count;
}

// 이진트리의 높이를 구하는 함수
int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + MAX(get_height(node->left), get_height(node->right));
	return height;
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

//             n6
//        n2         n5
//    n1          n3    n4 

int main(void) {
	
	printf("노드의 개수 : %d\n", get_node_count(root));
	printf("단말 노드의 개수 : %d\n", get_leaf_count(root));
	printf("이진트리의 높이 : %d\n", get_height(root));
	return 0;
}