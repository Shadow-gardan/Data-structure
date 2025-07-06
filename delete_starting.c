#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct Node* temp = *head; 
    *head = (*head)->next;     
    printf("Deleted node with data: %d\n", temp->data);
    free(temp);             
}


void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Adding sample data
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);	    

    printf("Original List:\n");
    display(head);

    // Delete node from beginning
    deleteFromBeginning(&head);
    deleteFromBeginning(&head);
    deleteFromBeginning(&head);
    display(head);

    return 0;
}

