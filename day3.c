//day3
#include <stdio.h>
int main() {
    int n, k, i, comparisons = 0, foundIndex = -1;

    // Read the size of the array
    scanf("%d", &n);
    int arr[n];

    // Read the array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the key to search
    scanf("%d", &k);

    // Perform linear search
    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            foundIndex = i;
            break;
        }
    }

    // Output the result
    if (foundIndex != -1) {
        printf("Found at index %d\n", foundIndex);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}