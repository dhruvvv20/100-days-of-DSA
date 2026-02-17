#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if(n == 0) {
        printf("No elements\n");
        return 0;
    }
    int max = arr[0];
    int min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }
    printf("Max: %d\nMin: %d\n", max, min);
    return 0;
}