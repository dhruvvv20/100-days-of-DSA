#include <stdio.h>

#define MAX 1000

int main() {
    int arr[MAX];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // Hash map using array (for simplicity)
    int map[20001]; // to handle negative sums
    for (int i = 0; i < 20001; i++) map[i] = -2;

    int offset = 10000;

    map[offset] = -1; // sum = 0 at index -1

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int key = prefixSum + offset;

        if (map[key] != -2) {
            int len = i - map[key];
            if (len > maxLen)
                maxLen = len;
        } else {
            map[key] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}