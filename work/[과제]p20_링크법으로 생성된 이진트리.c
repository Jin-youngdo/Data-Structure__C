// 11���� ���� 4 : p.20 ��ũ������ ������ ����Ʈ��
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {       // Ʈ�� ����ü 
    int data;
    struct TreeNode* left, * right;
} TreeNode;

// ��Ʈ ��� �� ���� Ʈ�� ����
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

// ���� ��ȸ
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("[%2d] ", root->data);
        inorder(root->right);
    }
}

// ���� ��ȸ
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("[%2d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// ���� ��ȸ
void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("[%2d] ", root->data);
    }
}

int main(void)
{
    printf("���� ��ȸ = ");
    inorder(root);

    printf("\n\n���� ��ȸ = ");
    preorder(root);

    printf("\n\n���� ��ȸ = ");
    postorder(root);
    return 0;
}