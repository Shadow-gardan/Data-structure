#include <stdio.h>

#define MAX 100

int arr[MAX], top = -1;
int size = sizeof(arr) / sizeof(arr[0]);

void push(int data) {
    if(top >= size - 1) {
        printf("Stack Overflow\n");
    } else {
        arr[++top] = data;
        printf("Data was inserted\n");
    }
}

void pop() {
	
	int a;
	printf("You want to delete the number from  stack\n");
	printf("Enter 1 to yes 0 to no\n");
	scanf("%d",&a);
	
	int b,i;
    printf("How many data want to delete: ");
    scanf("%d",&b);
    
    
	
        if(a==1 ){
	
    		if(top == -1) {
        	printf("Stack Underflow\n");
    		} 
			else {
				for(i = 0; i < b; i++) {
    	    		arr[top--] = 0;
    			}
    			printf("Data was deleted\n");
    	    	display();
    		}
		}
		else{
		display();
		return;
		}          
    

}

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        int i;
        printf("Stack contents:\n");
        for(i = 0; i <= top; i++) {
            printf("%d\n", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, value;

    printf("How many elements do you want to enter? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &value); 
        push(value);             
    }
	
	
    display();
	 
   pop();

    return 0;
}

