#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node at the "start" (make it the new root)
struct Node* insertAtStart(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    newNode->left = root;  // Make current tree the left child
    return newNode;        // Return new node as the new root
}

// Inorder traversal (for display)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function
int main() {
    struct Node* root = NULL;

    root = insertAtStart(root, 10);  // First node becomes root
    root = insertAtStart(root, 20);  // New root with previous tree as left child
    root = insertAtStart(root, 30);  // Again insert at start

    printf("Inorder Traversal: ");
    inorder(root);  // Will show left-heavy tree
    printf("\n");

    return 0;
}

