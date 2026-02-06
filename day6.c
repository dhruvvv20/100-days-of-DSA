//day6

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Two-pointer technique to remove duplicates
    int i = 0;  // pointer for unique elements
    
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }
    
    // Print unique elements
    for (int k = 0; k <= i; k++) {
        printf("%d", arr[k]);
        if (k < i) printf(" ");
    }
    printf("\n");
    
    return 0;
}
