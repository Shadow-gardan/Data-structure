#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to delete a subtree
void deleteTree(struct Node* root) {
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    printf("Deleting node: %d\n", root->data);
    free(root);
}

// Recursive function to find and delete a node by value
void deleteNodeByValue(struct Node* root, int value) {
    if (root == NULL)
        return;

    if (root->left && root->left->data == value) {
        deleteTree(root->left);
        root->left = NULL;
        return;
    }

    if (root->right && root->right->data == value) {
        deleteTree(root->right);
        root->right = NULL;
        return;
    }

    // Recur on left and right
    deleteNodeByValue(root->left, value);
    deleteNodeByValue(root->right, value);
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    // Create a binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    // Delete node with value 2 (and its subtree)
    deleteNodeByValue(root, 2);

    // You can implement traversal here to verify remaining tree

    return 0;
}

