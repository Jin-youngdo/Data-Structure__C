// p.312 ���α׷�8.14 : ����Ž��Ʈ���� �̿��� ������� [����]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define _CRT_NO_SECURE_WARNINGS
#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

// ����ü element�� ����
typedef struct {	
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
}element;

// Ʈ�� ��� ����ü ����
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// element�� ������ �ΰ��� ���ϴ� �Լ�
int compare(element key1, element key2) {
	return strcmp(key1.word, key2.word);
}

// ����Ž��Ʈ�� ��� �Լ�[���� ��ȸ]
void display(TreeNode* node) {
	if (node != NULL) {
		printf("(");
		display(node->left);
		printf(" [%s : %s] ", node->key.word, node->key.meaning);
		printf(")");
		display(node->right);
	}
}

// ����Ž��Ʈ�� Ž�� �Լ�
TreeNode* search(TreeNode* node, element key) {

	while (node != NULL) {
		if (compare(key, node->key) == 0)
			return node;
		else if (compare(key, node->key) < 0)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;	// Ž���� �������� ��� NULL ��ȯ
}

// ��� ���� �Լ�
TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));

	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// ��� ���� �Լ�
TreeNode* insert_node(TreeNode* node, element key) {
	// Ʈ���� �����Ͻ� ��� ���� �� ��ȯ
	if (node == NULL)
		return new_node(key);
	// Ʈ���� ������ �ƴҰ�� ��ȯ������ Ʈ�� Ž��
	if (compare(key, node->key) < 0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key) > 0)
		node->right = insert_node(node->right, key);
	return node;
}

// ����Ž��Ʈ�� �� ���� �ܸ� ���(Ʈ���� �ּҰ�) Ž�� �Լ�
TreeNode* min_value_node(TreeNode* root) {
	TreeNode* current = root;

	while (current->left != NULL)
		current = current->left;
	return current;
}

// ��� ���� �Լ�
TreeNode* delete_node(TreeNode* root, element key) {
	if (root == NULL)
		return root;
	// compare(root->key, key) < 0 �� ��� ���� ���� Ʈ���� �ִ� ���� 
	if (compare(root->key, key) < 0)
		root->left = delete_node(root->left, key);
	// compare(root->key, key) > 0 �� ��� ������ ���� Ʈ���� �ִ� ����
	else if (compare(root->key, key) > 0)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ�� ���� ��� ��� ����
	else {
		// �ڽ��� �ϳ��ų� ���� ���
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
		// �ڽ��� �Ѵ� �ִ� ��� ���� �ļ��� ��������(������ ����Ʈ���� �ּҰ� ���)
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;	// ���� �ļ����� Ű���� ����
		root->right = delete_node(root->right, temp->key);	// ���� ����� ���� �ļ��� ����
	}
	return root;
}

void help() {
	printf("\n-----------------------------------------------------\n");
	printf("i : �Է�   d : ����   s : Ž��   p : ���   q : ����\n");
	printf("-----------------------------------------------------\n");
	printf("������ �۾� : ");
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
			printf("�ܾ� �Է� : ");
			scanf(" %s", e.word);
			getchar();
			printf("�ǹ� �Է� : ");
			scanf(" %s", e.meaning);
			getchar();
			root = insert_node(root, e);
			break;
		case 'd':
			printf("������ �ܾ� : ");
			scanf(" %s", e.word);
			root = delete_node(root, e);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("Ž���� �ܾ� : ");
			scanf(" %s", e.word);
			getchar();
			tmp = search(root, e);
			if (tmp != NULL)
				printf("�ǹ� : %s\n", tmp->key.meaning);
			else
				printf("�ܾ �������� �ʽ��ϴ�.\n");
			break;
		case 'q':
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		}
	}
	return 0;
}