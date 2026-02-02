#include<stdio.h>
//Day2
#define MAX_SIZE 100
int main() {
    int n, arr[MAX_SIZE], pos;

    // Read the number of elements
    scanf("%d", &n);

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    

    // Read the position to delete
    scanf("%d", &pos);

    // Adjust position to be zero-based index
    int index = pos - 1;

    // Shift elements to the left to delete the element at index
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print the updated array
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}