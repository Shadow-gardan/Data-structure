#include <stdio.h>
#include <stdlib.h>

// Define the structure of the node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node in the "middle" between current root and a new right child
struct Node* insertInMiddle(struct Node* root, int newData, int rightSubtreeData) {
    struct Node* newRoot = createNode(newData);        // Create middle node
    struct Node* rightChild = createNode(rightSubtreeData);  // Create new right subtree

    newRoot->left = root;           // Old tree becomes left child
    newRoot->right = rightChild;    // New right child
    return newRoot;                 // New root of the tree
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

    // Start with a base tree
    root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);

    printf("Original tree inorder: ");
    inorder(root);
    printf("\n");

    // Insert a node in the "middle"
    root = insertInMiddle(root, 20, 25);

    printf("After inserting in middle: ");
    inorder(root);
    printf("\n");

    return 0;
}

