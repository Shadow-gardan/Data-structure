#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("Circular linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
}

int main() {
    insert(1);
    insert(66);
    insert(12);
    insert(87);
    insert(56);
    display();
    return 0;
}

