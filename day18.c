#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);
    k = k % n; // to handle k >= n
    int temp[n];
    for(int i = 0; i < n; i++) {
        temp[(i + k) % n] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
    return 0;
}
