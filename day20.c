#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    long long prefix[n+1];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + arr[i-1];
    }
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(prefix[j] == prefix[i]) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}