#include <stdio.h>
#include <stdlib.h>

// Define structure
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

// Queue structure for level-order traversal
struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* treeNode) {
    struct QueueNode* temp = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    struct Node* node = temp->treeNode;
    free(temp);
    return node;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Insert at the end using level order
void insertAtEnd(struct Node** root, int data) {
    struct Node* newNode = createNode(data);

    // If tree is empty
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Level-order traversal to find the right spot
    struct Queue* q = createQueue();
    enqueue(q, *root);

    while (!isEmpty(q)) {
        struct Node* temp = dequeue(q);

        if (temp->left == NULL) {
            temp->left = newNode;
            break;
        } else {
            enqueue(q, temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            break;
        } else {
            enqueue(q, temp->right);
        }
    }

    free(q);  // Clean up queue
}

// Inorder traversal for display
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function
int main() {
    struct Node* root = NULL;

    insertAtEnd(&root, 10);
    insertAtEnd(&root, 20);
    insertAtEnd(&root, 30);
    insertAtEnd(&root, 40);
    insertAtEnd(&root, 50);

    printf("Inorder traversal after inserting at end:\n");
    inorder(root);
    printf("\n");

    return 0;
}

