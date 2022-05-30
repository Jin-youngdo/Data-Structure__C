// p.312 프로그램8.14 : 이진탐색트리를 이용한 영어사전 [과제]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define _CRT_NO_SECURE_WARNINGS
#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

// 구조체 element형 정의
typedef struct {	
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
}element;

// 트리 노드 구조체 정의
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// element형 데이터 두개를 비교하는 함수
int compare(element key1, element key2) {
	return strcmp(key1.word, key2.word);
}

// 이진탐색트리 출력 함수[중위 순회]
void display(TreeNode* node) {
	if (node != NULL) {
		printf("(");
		display(node->left);
		printf(" [%s : %s] ", node->key.word, node->key.meaning);
		printf(")");
		display(node->right);
	}
}

// 이진탐색트리 탐색 함수
TreeNode* search(TreeNode* node, element key) {

	while (node != NULL) {
		if (compare(key, node->key) == 0)
			return node;
		else if (compare(key, node->key) < 0)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;	// 탐색에 실패했을 경우 NULL 반환
}

// 노드 생성 함수
TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));

	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// 노드 삽입 함수
TreeNode* insert_node(TreeNode* node, element key) {
	// 트리가 공백일시 노드 생성 후 반환
	if (node == NULL)
		return new_node(key);
	// 트리가 공백이 아닐경우 순환적으로 트리 탐색
	if (compare(key, node->key) < 0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key) > 0)
		node->right = insert_node(node->right, key);
	return node;
}

// 이진탐색트리 맨 왼쪽 단말 노드(트리의 최소값) 탐색 함수
TreeNode* min_value_node(TreeNode* root) {
	TreeNode* current = root;

	while (current->left != NULL)
		current = current->left;
	return current;
}

// 노드 삭제 함수
TreeNode* delete_node(TreeNode* root, element key) {
	if (root == NULL)
		return root;
	// compare(root->key, key) < 0 인 경우 왼쪽 서브 트리에 있는 것임 
	if (compare(root->key, key) < 0)
		root->left = delete_node(root->left, key);
	// compare(root->key, key) > 0 인 경우 오른쪽 서브 트리에 있는 것임
	else if (compare(root->key, key) > 0)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같을 경우 노드 삭제
	else {
		// 자식이 하나거나 없는 경우
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// 자식이 둘다 있는 경우 중위 후속자 가져오기(오른쪽 서브트리의 최소값 노드)
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;	// 중위 후속자의 키값을 전달
		root->right = delete_node(root->right, temp->key);	// 현재 노드의 중위 후속자 제거
	}
	return root;
}

void help() {
	printf("\n-----------------------------------------------------\n");
	printf("i : 입력   d : 삭제   s : 탐색   p : 출력   q : 종료\n");
	printf("-----------------------------------------------------\n");
	printf("수행할 작업 : ");
}

int main(void) {
	char command;
	element e;
	TreeNode* root = NULL;
	TreeNode* tmp;

	while(1) {
		help();
		scanf(" %c", &command);
		getchar();

		switch (command) {
		case 'i':
			printf("단어 입력 : ");
			scanf(" %s", e.word);
			getchar();
			printf("의미 입력 : ");
			scanf(" %s", e.meaning);
			getchar();
			root = insert_node(root, e);
			break;
		case 'd':
			printf("삭제할 단어 : ");
			scanf(" %s", e.word);
			root = delete_node(root, e);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("탐색할 단어 : ");
			scanf(" %s", e.word);
			getchar();
			tmp = search(root, e);
			if (tmp != NULL)
				printf("의미 : %s\n", tmp->key.meaning);
			else
				printf("단어가 존재하지 않습니다.\n");
			break;
		case 'q':
			printf("프로그램을 종료합니다.\n");
			return 0;
		}
	}
	return 0;
}