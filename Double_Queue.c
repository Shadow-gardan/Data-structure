#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

void insertRear(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full at rear\n");
        return;
    }
    if (front == -1) front = 0;
    deque[++rear] = value;
    printf("Inserted at rear: %d\n", value);
}

void insertFront(int value) {
    if (front <= 0) {
        printf("No space at front!\n");
        return;
    }
    deque[--front] = value;
    printf("Inserted at front: %d\n", value);
}

void deleteFront() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Deleted from front: %d\n", deque[front++]);
}

void deleteRear() {
    if (rear == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Deleted from rear: %d\n", deque[rear--]);
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    int i;
    printf("Queue: ");
    for (i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();
    deleteFront();
    deleteRear();
    display();
    return 0;
}

