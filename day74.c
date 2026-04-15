#include <stdio.h>
#include <string.h>

struct Candidate {
    char name[50];
    int count;
};

int main() {
    int n;
    scanf("%d", &n);

    struct Candidate arr[1000];
    int size = 0;

    for (int i = 0; i < n; i++) {
        char name[50];
        scanf("%s", name);

        int found = 0;

        // Check if candidate already exists
        for (int j = 0; j < size; j++) {
            if (strcmp(arr[j].name, name) == 0) {
                arr[j].count++;
                found = 1;
                break;
            }
        }

        // New candidate
        if (!found) {
            strcpy(arr[size].name, name);
            arr[size].count = 1;
            size++;
        }
    }

    // Find winner
    char winner[50];
    int maxVotes = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i].count > maxVotes) {
            maxVotes = arr[i].count;
            strcpy(winner, arr[i].name);
        }
        else if (arr[i].count == maxVotes) {
            // Lexicographically smaller
            if (strcmp(arr[i].name, winner) < 0) {
                strcpy(winner, arr[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}