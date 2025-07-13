#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to delete the deepest node
void deleteDeepest(struct Node* root, struct Node* delNode) {
    if (root == NULL || delNode == NULL)
        return;

    if (root->left) {
        if (root->left == delNode) {
            free(root->left);
            root->left = NULL;
            return;
        } else {
            deleteDeepest(root->left, delNode);
        }
    }

    if (root->right) {
        if (root->right == delNode) {
            free(root->right);
            root->right = NULL;
            return;
        } else {
            deleteDeepest(root->right, delNode);
        }
    }
}

// Function to find and delete the deepest node
void deleteLastNode(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* temp;
    struct Node* last;
    struct Node** queue = (struct Node**)malloc(100 * sizeof(struct Node*));  // Simple queue
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        temp = queue[front++];
        if (temp->left)
            queue[rear++] = temp->left;
        if (temp->right)
            queue[rear++] = temp->right;
    }

    last = temp;  // Deepest, rightmost node
    deleteDeepest(root, last);

    free(queue);
}

// In-order traversal (for testing)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // Create a sample tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    printf("In-order before deletion: ");
    inorder(root);

    deleteLastNode(root);  // deletes node 6 (deepest rightmost)

    printf("\nIn-order after deletion: ");
    inorder(root);

    return 0;
}

