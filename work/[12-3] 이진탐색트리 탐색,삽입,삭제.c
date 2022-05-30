// p.306 ���α׷� 8.13 : ����Ž��Ʈ�� Ž��/����/���� ����
#include <stdio.h>
#include <stdlib.h>
#define _CRT_NO_SECURE_WARNINGS

typedef int element;	// element �ڷ��� ����
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// ����Ž��Ʈ�� Ž�� �Լ�
TreeNode* search(TreeNode* node, element key) {

	// Ž��Ű�� ���� Ʈ�� ��Ʈ�� Ű���� ���Ͽ� ���� ��� ���� Ʈ�� ��Ʈ,
	// Ŭ ��� ������ Ʈ�� ��Ʈ�� �̵��ϸ� Ž��Ű�� �ִ� ��Ʈ Ž�� �� ��ȯ
	while (node != NULL) {
		if (key == node->key)	// Ž��Ű�� ���� Ʈ�� ��Ʈ�� Ű���� ���� ��� ��ȯ
			return node;
		else if (key < node->key)	
			return search(node->left, key);
		else
			return search(node->right, key);
	}
	return NULL;	// Ʈ���� ������ ��� NULL ��ȯ
}

// ����Ž��Ʈ�� Ű���� ���޹޾� ��� ������ ��ȯ �Լ�
TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// ����Ž��Ʈ�� ���� �Լ�
TreeNode* insert_node(TreeNode* node, element key) {
	// Ʈ���� ������ ��� ���ο� ��� ���� �� ��ȯ
	if (node == NULL)
		return new_node(key);

	// Ʈ���� ������ �ƴ� ��� ���� Ʈ�� ��Ʈ�� Ű ���� ������ Ű ���� ���Ͽ�
	// ���� ��� ���� Ʈ�� ��Ʈ�� ���� ��Ʈ�� ����, Ŭ ��� �����ʿ� ����
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// ��� ���� �� ����� ��Ʈ ������ ��ȯ
	return node;
}

// ����Ž��Ʈ�� �� ���� �ܸ� ���(Ʈ���� �ּҰ�) Ž�� �Լ�
TreeNode* min_value_node(TreeNode* node) {

	// ���� Ʈ���� ���� ��Ʈ�� NULL�� �� �� ���� ���� Ʈ�� ��Ʈ�� �̵�
	while (node->left != NULL) {
		node = node->left;
	}
	return node;
}

// ����Ž��Ʈ�� Ư��Ű ��� ���� �Լ�
TreeNode* delete_node(TreeNode* root, int key) {
	TreeNode* temp = root;	// ������ ��带 ���� �� ���� ��ȯ �� Ʈ�� ����
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

// ����Ž��Ʈ�� ���� ��ȸ �� ��� �Լ�
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

void menu() {
	printf("\n----------------------------------------------------\n");
	printf("1 : Ž��   2 : ����   3 : ����   4 : ���   5 : ����\n");
	printf("----------------------------------------------------\n");
	printf("������ �۾� : ");
}

int main(void) {
	TreeNode* root = NULL;
	TreeNode* temp = NULL;
	int select_node, command;

	for (int i = 70; i > 0; i -= 10) {
		root = insert_node(root, i);
	}

	printf("����Ž��Ʈ�� ���� ��ȸ ���\n");
	inorder(root); printf("\n");

	while (1) {
		menu();
		scanf("%d", &command);

		switch (command) {
		case 1: 
			printf("\n\nŽ���� ��� �Է� : ");
			scanf("%d", &select_node);
			if (search(root, select_node) != NULL)
				printf("����Ž��Ʈ������ %d �߰� ����\n", select_node);
			else
				printf("����Ž��Ʈ������ %d �߰� ����\n", select_node);
			break;
		case 2:
			printf("\n\n������ ��� �Է� : ");
			scanf("%d", &select_node);
			if (search(root, select_node) != NULL) {
				printf("�ߺ� ��� �Դϴ�. �ٽ� �Է����ּ���.\n");
				continue;
			}
			else if(search(root, select_node) == NULL) {
				root = insert_node(root, select_node);
				printf("���������� ���� �Ϸ� �Ͽ����ϴ�.\n");
				break;
			}
			else {
				printf("�߸� �Է��ϼ̽��ϴ�..\n");
				continue;
			}
		case 3:
			printf("\n\n������ ��� �Է� : ");
			scanf("%d", &select_node);
			root = delete_node(root, select_node);
			printf("���������� ���� �Ǿ����ϴ�.\n");
			break;
		case 4:
			inorder(root); printf("\n");
			break;
		case 5:
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		}
	}
	return 0;
}