// p.310 트리의 높이 구하기, 평균 탐색 횟수 결과 출력 [과제]
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(a, b) ( a>b ? a:b )
#define _CRT_NO_SECURE_WARNINGS

typedef int element;	// element 자료형 선언
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// 이진탐색트리 키값을 전달받아 노드 생성후 반환 함수
TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));

	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// 이진탐색트리 삽입 함수
TreeNode* insert_node(TreeNode* node, element key) {
	if (node == NULL)
		return new_node(key);

	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}

// 노드의 높이를 구하는 함수
int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

// 평균 검색 횟수 출력 함수
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
	//                 트리 
	//                  7
	//             1         9
	//               5          8 
	//            2     6
	//               3 
	//                 4
	printf("트리의 높이(h) : %d\n", get_height(root));
	printf("트리 평균 검색 횟수(log₂h) : %lf\n", get_search_avg(root));
	return 0;
}