#include <stdio.h>
#include <stdlib.h>

// ���� Ʈ�� ��带 �����ϴ� ����ü
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ��� ���� �Լ�
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("�޸� �Ҵ� ����\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// ���� ��ȸ
void preorder(TreeNode* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

// ���� ��ȸ
void inorder(TreeNode* node) {
    if (node == NULL) return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

// ���� ��ȸ
void postorder(TreeNode* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

// Ʈ���� ���� ���
int getHeight(TreeNode* node) {
    if (node == NULL) return -1;
    int left = getHeight(node->left);
    int right = getHeight(node->right);
    return (left > right ? left : right) + 1;
}

// ��ü ��� �� ���
int countNodes(TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

// ���� ��� �� ���
int countLeaves(TreeNode* node) {
    if (node == NULL) return 0;
    if (node->left == NULL && node->right == NULL) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

// ��� �� ���� ���
int getSum(TreeNode* node) {
    if (node == NULL) return 0;
    return node->data + getSum(node->left) + getSum(node->right);
}

// �ִ� ã��
int getMax(TreeNode* node) {
    if (node == NULL) return 0; // INT_MIN

    int max = node->data;
    int leftMax = getMax(node->left);
    int rightMax = getMax(node->right);

    if (leftMax > max) max = leftMax;
    if (rightMax > max) max = rightMax;

    return max;
}

// �־��� ������ ���ϴ� ��� ���
void searchRange(TreeNode* node, int min, int max) {
    if (node == NULL) return;

    // ���� ��ȸ�� �����ϸ鼭 ���Ǹ� �߰�
    searchRange(node->left, min, max);

    if (node->data > min && node->data < max) {
        printf("%d ", node->data);
    }

    searchRange(node->right, min, max);
}

// Ʈ�� �޸� ����
void freeTree(TreeNode* node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

// ���� �Լ�
int main() {
    // Ʈ�� ����
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);

    // ��ȸ ���
    printf("���� ��ȸ: ");
    preorder(root);
    printf("\n");

    printf("���� ��ȸ: ");
    inorder(root);
    printf("\n");

    printf("���� ��ȸ: ");
    postorder(root);
    printf("\n");

    // Ʈ�� �Ӽ� ���
    printf("\nƮ�� ����: %d\n", getHeight(root));
    printf("��ü ��� ��: %d\n", countNodes(root));
    printf("���� ��� ��: %d\n", countLeaves(root));

    // �߰� ��� ���
    printf("��� �� ����: %d\n", getSum(root));
    printf("�ִ�: %d\n", getMax(root));

    printf("\n���� 6 �̻� 20 ������ ���: ");
    searchRange(root, 6, 20);
    printf("\n");

    freeTree(root);
    return 0;
}
