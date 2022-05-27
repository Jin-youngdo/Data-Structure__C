// 연결리스트로 구현한 이진트리
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Tree {
	int data;
	struct Tree* left, * right;
}Tree;
//		n1
//	   / |
//   n2  n3

int main(void) {
	Tree* n1 = (Tree*)malloc(sizeof(Tree));
	Tree* n2 = (Tree*)malloc(sizeof(Tree));
	Tree* n3 = (Tree*)malloc(sizeof(Tree));

	n1->data = 10;
	n1->left = n2;
	n1->right = n3;

	n2->data = 20;	n2->left = NULL;	n2->right = NULL;
	n3->data = 30;	n3->left = NULL;	n3->right = NULL;

	free(n1); free(n2); free(n3);
	return 0;
}