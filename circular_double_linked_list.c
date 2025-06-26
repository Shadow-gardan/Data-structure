#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int value;
    struct node* next;
    struct node* prev;
} node;

node* head = NULL;


node* createNode(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->value = data;
    newnode->next = newnode->prev = NULL;
    return newnode;
}


void insertEnd(int data) {
    node* newnode = createNode(data); // Fixed: corrected function name

    if (head == NULL) {
        newnode->next = newnode->prev = newnode;
        head = newnode;
        return;
    }

    node* temp = head->prev;

    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = head;
    head->prev = newnode;
}


void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node* temp = head;
    printf("List: ");
    do {
        printf("%d->", temp->value);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}


int main() {
    insertEnd(13);
    insertEnd(56);
    insertEnd(94);
    insertEnd(45);
    insertEnd(34);

    display(); 

    return 0;
}

