#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to delete the entire tree
void deleteTree(struct Node* root) {
    if (root == NULL)
        return;

    // First delete both subtrees
    deleteTree(root->left);
    deleteTree(root->right);

    // Then delete the node itself
    printf("Deleting node with data: %d\n", root->data);
    free(root);
}

// Helper function to create a new tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    // Creating a simple binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // Delete the tree
    deleteTree(root);
    root = NULL; // good practice to avoid dangling pointer

    return 0;
}

