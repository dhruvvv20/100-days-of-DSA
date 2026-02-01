//Day1
#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int n, arr[MAX_SIZE], pos, x;

    // Read the number of elements
    scanf("%d", &n);

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the position and the element to insert
    scanf("%d", &pos);
    scanf("%d", &x);

    // Adjust position to be zero-based index
    int index = pos - 1;

    // Shift elements to the right to make space for the new element
    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[index] = x;

    // Print the updated array
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}