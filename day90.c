#include <stdio.h>

// Function to check if boards can be painted with k painters
int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (currTime + boards[i] <= maxTime) {
            currTime += boards[i];
        } else {
            painters++;
            currTime = boards[i];

            if (painters > k) {
                return 0; // Not possible
            }
        }
    }
    return 1; // Possible
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int low = boards[0], high = 0;

    // Find max element and total sum
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            result = mid;
            high = mid - 1; // Try smaller time
        } else {
            low = mid + 1;  // Increase time
        }
    }

    return result;
}

int main() {
    int n, k;

    // Input
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    // Output
    printf("%d\n", minTime(boards, n, k));

    return 0;
}