// 11주차 과제 4 : p.20 링크법으로 생성된 이진트리
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {       // 트리 구조체 
    int data;
    struct TreeNode* left, * right;
} TreeNode;

// 루트 노드 및 서브 트리 정의
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

// 중위 순회
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("[%2d] ", root->data);
        inorder(root->right);
    }
}

// 전위 순회
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("[%2d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 후위 순회
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("[%2d] ", root->data);
    }
}

int main(void)
{
    printf("중위 순회 = ");
    inorder(root);

    printf("\n\n전위 순회 = ");
    preorder(root);

    printf("\n\n후위 순회 = ");
    postorder(root);
    return 0;
}