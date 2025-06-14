#include <stdio.h>

int top = -1, i;
int size = 5;
char arr1[5], arr2[5];

void push() {
    char value;
    for (i = 0; i < size; i++) {
        if (top == size - 1) {
            printf("Stack is overflow\n");
            break;
        } else {
            printf("Enter the data %d: ", i + 1);
            scanf(" %c", &value);
            arr1[++top] = value;
        }
    }

    printf("Stored data in stack:\n");
    for (i = 0; i <= top; i++) {
        printf("%c ", arr1[i]);
    }
    printf("\n");
}

void Reverse() {
    printf("Reversed data:\n");
    for (i = 0; i <= top; i++) {
        arr2[i] = arr1[top - i];
    }
    for (i = 0; i <= top; i++) {
        printf("%c ", arr2[i]);
    }
    printf("\n");
}

int main() {
    push();

    int tr;
    printf("Do you want to reverse the data?\n");
    printf("Enter 1 for yes or 0 for no: ");
    scanf("%d", &tr);

    if (tr == 1) {
        Reverse();
    }

    return 0;
}

