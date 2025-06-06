#include <stdio.h>
#define SIZE 5  

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % SIZE);
}

int isEmpty() {
    return (front == -1);
}


void enqueue() {
    if (isFull()) {
        printf("Queue is Full!\n");
        return;
    }

    if (isEmpty()) {
        front = 0;
    }
    int a,i;
    
    for(i=0;i<5;i++){
		printf("Enter the %d elemenet : ",i);
    	scanf("%d",&a);
	    rear = (rear + 1) % SIZE;
	    queue[rear] = a;
	}
    display();
}


void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }
	int i,a;
	printf("How many element was deleted : ");
	scanf("%d",&a);
	for(i=0;i<a;i++){
	
	    printf("Deleted %d\n", queue[front]);
		
	    if (front == rear) {
	        front = rear = -1;
	    } else {
	        front = (front + 1) % SIZE;
	    }
	}
    display();
}


void display() {
    if (isEmpty()) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function for testing
int main() {
    enqueue();
   
    dequeue();

    return 0;
}

