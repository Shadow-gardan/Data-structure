#include <stdio.h>
#define MAX 100

int arr[MAX];
int size = 0; 

void Enter() {
    int i, value;
    printf("How many data items do you want to enter: ");
    scanf("%d", &size);
    
    printf("Enter %d sorted values (ascending order):\n", size);
    for (i = 0; i < size; i++) {
        printf("Enter data %d: ", i + 1);
        scanf("%d", &value);
        arr[i] = value;
    }
    printf("Data was entered.\n");
}

void Binary_search() {
    int f;
    printf("Enter the data to search: ");
    scanf("%d", &f);

    int first = 0, last = size - 1, mid;
    while (first <= last) {
        mid = (first + last) / 2;
        if (arr[mid] == f) {
            printf("Value %d is found at index %d.\n", f, mid);
            return;
        } else if (arr[mid] < f) {
            first = mid + 1;
        } else {
            last = mid - 1;
        }
    }
    printf("Value %d not found in the array.\n", f);
}

int main() {
    Enter();
    Binary_search();
    return 0;
}

