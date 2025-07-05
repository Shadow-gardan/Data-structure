#include <stdio.h>
#include <stdlib.h>

// Define a node for the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int search(struct Node* root, int target) {
    if (root == NULL) {
        return 0; 
    }

    if (root->data == target) {
        return 1; 
    }

    if (target < root->data)
        return search(root->left, target);
    else
        return search(root->right, target);
}

int main() {

    struct Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("Value %d found in the tree.\n", key);
    else
        printf("Value %d not found in the tree.\n", key);

    return 0;
}

