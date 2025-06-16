#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void insertAtEnd(struct Node** headRef) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the data to insert at the end: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (*headRef == NULL) {

        *headRef = newNode;
        return;
    }

 
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    struct Node* head = NULL;
    int choice;

    
    do {
        insertAtEnd(&head);
        printf("Do you want to add another node at the end (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

    printf("\nThe linked list is:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

