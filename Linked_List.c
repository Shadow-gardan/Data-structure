#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	struct node{
	
		int data;
		struct node*next;
	};
	
	struct node*head;
	struct node*temp;
	head = 0;
	int choice = 1;
	struct node*newnode = 0;
	
	while(choice){
		newnode = (struct node*)malloc(sizeof(struct node));
		
		if (newnode == 0) {
        	printf("Memory allocation failed\n");
            return 1;
        }
		
		printf("Enter the data: ");
		scanf("%d",&newnode -> data);
		newnode -> next = 0;
		
		
		if(head == 0){
			head = temp =newnode;
		}
		else{
			temp -> next = newnode;
			temp = newnode;
		}
		
		printf("Do you want to another data 1/0 : \n");
		scanf("%d",&choice);
		
		temp = head;
		while (temp != 0){
			printf("%d\n",temp->data);
			temp = temp->next;
		}
		
	}
	
    return 0;
}

