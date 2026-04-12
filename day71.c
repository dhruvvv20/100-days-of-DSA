#include <stdio.h>

#define EMPTY -1

int table[1000];

// Initialize table
void init(int m) {
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }
}

// Insert using quadratic probing
void insert(int key, int m) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i*i) % m;

        if (table[index] == EMPTY) {
            table[index] = key;
            return;
        }
    }
}

// Search using quadratic probing
int search(int key, int m) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i*i) % m;

        if (table[index] == EMPTY) {
            return 0; // not found
        }

        if (table[index] == key) {
            return 1; // found
        }
    }

    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    init(m);

    while (q--) {
        char op[10];
        int x;

        scanf("%s %d", op, &x);

        if (op[0] == 'I') {
            insert(x, m);
        } else if (op[0] == 'S') {
            if (search(x, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}