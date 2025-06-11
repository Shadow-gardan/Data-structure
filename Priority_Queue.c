#include <stdio.h>
#define MAX 100

int queue[MAX];
int priority[MAX];
int size = 0;

void enqueue() {
    int v, p, e, d, i;

    printf("How many data to enter: ");
    scanf("%d", &d);

    for (e = 0; e < d; e++) {
        if (size == MAX) {
            printf("Queue is full\n");
            return;
        }

        printf("Enter value and its priority (e.g. 10 3): ");
        scanf("%d %d", &v, &p);

        for (i = size - 1; i >= 0 && p > priority[i]; i--) {
            queue[i + 1] = queue[i];
            priority[i + 1] = priority[i];
        }

        queue[i + 1] = v;
        priority[i + 1] = p;
        size++;
    }

    display();
}

void dequeue() {
    int i, d, a;

    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("How many Data to Delete: ");
    scanf("%d", &d);

    for (a = 0; a < d; a++) {
        if (size == 0) {
            printf("Queue is empty\n");
            return;
        }

        printf("Dequeued: %d\n", queue[0]);

        for (i = 1; i < size; i++) {
            queue[i - 1] = queue[i];
            priority[i - 1] = priority[i];
        }

        size--;
    }

    display();
}

void display() {
    int i;

    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue (value:priority):\n");
    for (i = 0; i < size; i++) {
        printf("%d:%d ", queue[i], priority[i]);
    }
    printf("\n");
}

int main() {
    enqueue();
    dequeue();
    return 0;
}

