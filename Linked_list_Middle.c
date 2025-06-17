#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtPosition(struct Node** headRef, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the data to insert: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    struct Node* temp = *headRef;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Invalid position. List is shorter than %d nodes.\n", position);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    struct Node* head = NULL;
    int choice, position;

    
    do {
        printf("Enter the position to insert the new node (1 = start): ");
        scanf("%d", &position);
        insertAtPosition(&head, position);

        printf("Do you want to insert another node (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice == 1);

   
    printf("\nThe linked list\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}

