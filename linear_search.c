#include <stdio.h>

void linear_search() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 11, 12, 14, 13};
    int f, i;
    int found = 0;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Enter the number to search: ");
    scanf("%d", &f);

    for (i = 0; i < n; i++) {
        if (arr[i] == f) {
            printf("Value is found at index %d: %d\n", i, f);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Value is not found.\n");
    }
}

int main() {
    linear_search();
    return 0;
}


