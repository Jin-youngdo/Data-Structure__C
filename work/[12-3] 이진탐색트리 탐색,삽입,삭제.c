// p.306 프로그램 8.13 : 이진탐색트리 탐색/삽입/삭제 연산
#include <stdio.h>
#include <stdlib.h>
#define _CRT_NO_SECURE_WARNINGS

typedef int element;	// element 자료형 선언
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// 이진탐색트리 탐색 함수
TreeNode* search(TreeNode* node, element key) {

	// 탐색키와 현재 트리 루트의 키값을 비교하여 작을 경우 왼쪽 트리 루트,
	// 클 경우 오른쪽 트리 루트로 이동하며 탐색키가 있는 루트 탐색 후 반환
	while (node != NULL) {
		if (key == node->key)	// 탐색키와 현재 트리 루트의 키값이 같을 경우 반환
			return node;
		else if (key < node->key)	
			return search(node->left, key);
		else
			return search(node->right, key);
	}
	return NULL;	// 트리가 공백일 경우 NULL 반환
}

// 이진탐색트리 키값을 전달받아 노드 생성후 반환 함수
TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// 이진탐색트리 삽입 함수
TreeNode* insert_node(TreeNode* node, element key) {
	// 트리가 공백일 경우 새로운 노드 생성 후 반환
	if (node == NULL)
		return new_node(key);

	// 트리가 공백이 아닐 경우 현재 트리 루트의 키 값과 삽입할 키 값을 비교하여
	// 작을 경우 현재 트리 루트의 왼쪽 루트에 삽입, 클 경우 오른쪽에 삽입
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// 노드 삽입 후 변경된 루트 포인터 반환
	return node;
}

// 이진탐색트리 맨 왼쪽 단말 노드(트리의 최소값) 탐색 함수
TreeNode* min_value_node(TreeNode* node) {

	// 현재 트리의 왼쪽 루트가 NULL이 될 떄 까지 왼쪽 트리 루트로 이동
	while (node->left != NULL) {
		node = node->left;
	}
	return node;
}

// 이진탐색트리 특정키 노드 삭제 함수
TreeNode* delete_node(TreeNode* root, int key) {
	TreeNode* temp = root;	// 제거할 노드를 삭제 후 새로 반환 할 트리 생성
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			temp = root->left;
			free(root);
			return temp;
		}
		
		temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

// 이진탐색트리 중위 순회 후 출력 함수
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

void menu() {
	printf("\n----------------------------------------------------\n");
	printf("1 : 탐색   2 : 삽입   3 : 삭제   4 : 출력   5 : 종료\n");
	printf("----------------------------------------------------\n");
	printf("수행할 작업 : ");
}

int main(void) {
	TreeNode* root = NULL;
	TreeNode* temp = NULL;
	int select_node, command;

	for (int i = 70; i > 0; i -= 10) {
		root = insert_node(root, i);
	}

	printf("이진탐색트리 중위 순회 결과\n");
	inorder(root); printf("\n");

	while (1) {
		menu();
		scanf("%d", &command);

		switch (command) {
		case 1: 
			printf("\n\n탐색할 노드 입력 : ");
			scanf("%d", &select_node);
			if (search(root, select_node) != NULL)
				printf("이진탐색트리에서 %d 발견 성공\n", select_node);
			else
				printf("이진탐색트리에서 %d 발견 실패\n", select_node);
			break;
		case 2:
			printf("\n\n삽입할 노드 입력 : ");
			scanf("%d", &select_node);
			if (search(root, select_node) != NULL) {
				printf("중복 노드 입니다. 다시 입력해주세요.\n");
				continue;
			}
			else if(search(root, select_node) == NULL) {
				root = insert_node(root, select_node);
				printf("정상적으로 삽입 완료 하였습니다.\n");
				break;
			}
			else {
				printf("잘못 입력하셨습니다..\n");
				continue;
			}
		case 3:
			printf("\n\n삭제할 노드 입력 : ");
			scanf("%d", &select_node);
			root = delete_node(root, select_node);
			printf("정상적으로 삭제 되었습니다.\n");
			break;
		case 4:
			inorder(root); printf("\n");
			break;
		case 5:
			printf("프로그램을 종료합니다.\n");
			return 0;
		}
	}
	return 0;
}