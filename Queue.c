#include <stdio.h>
#define MAX 100

int arr[MAX];
int front = -1, rear = -1;
int i;

void Inqueue() {
    int a, data;

    if (rear == MAX - 1) {
        printf("Queue is Full\n");
        return;
    }

    printf("How many data elements do you want to enter? ");
    scanf("%d", &a);

    for ( i = 0; i < a; i++) {
        if (rear == MAX - 1) {
            printf("Queue is Full. Cannot insert more elements.\n");
            break;
        }
        printf("Enter data %d: ", i + 1);
        scanf("%d", &data);
        if (front == -1) front = 0;  // First insertion
        arr[++rear] = data;
    }

    display();
}

void Dequeue() {
    int a;

    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }

    printf("How many data elements do you want to delete? ");
    scanf("%d", &a);

    for ( i = 0; i < a; i++) {
        if (front > rear) {
            printf("Queue is now empty.\n");
            break;
        }
        printf("Deleted: %d\n", arr[front]);
        front++;
    }

    display();
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    Inqueue();
    Dequeue();
    return 0;
}

