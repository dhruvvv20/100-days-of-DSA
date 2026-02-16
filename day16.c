#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    int i = 0;
    while (i < n) {
        int count = 1;
        while (i + 1 < n && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }
        printf("%d:%d ", arr[i], count);
        i++;
    }
    printf("\n");
    free(arr);
    return 0;
}
