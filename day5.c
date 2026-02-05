//day5
#include <stdio.h>
int main() {
    int p, q, i = 0, j = 0;

    // Read the number of entries in server log 1
    scanf("%d", &p);
    int log1[p];

    // Read the arrival times from server log 1
    for (i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    // Read the number of entries in server log 2
    scanf("%d", &q);
    int log2[q];

    // Read the arrival times from server log 2
    for (i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    // Merge the two logs into a single chronological log
    i = 0; // Reset i for merging
    j = 0; // Reset j for merging
    while (i < p && j < q) {
        if (log1[i] < log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    // If there are remaining entries in log1, print them
    while (i < p) {
        printf("%d ", log1[i]);
        i++;
    }

    // If there are remaining entries in log2, print them
    while (j < q) {
        printf("%d ", log2[j]);
        j++;
    }

    printf("\n"); // Print a newline at the end

    return 0;
}