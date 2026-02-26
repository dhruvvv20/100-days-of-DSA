#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* create_node(int val) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void insert_end(struct Node **head_ref, int val) {
    struct Node *new_node = create_node(val);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node *cur = *head_ref;
    while (cur->next)
        cur = cur->next;
    cur->next = new_node;
    new_node->prev = cur;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Node *head = NULL;
    for (int i = 0; i < n; ++i) {
        int x;
        if (scanf("%d", &x) != 1) x = 0;
        insert_end(&head, x);
    }

    struct Node *cur = head;
    int first = 1;
    while (cur) {
        if (!first) printf(" ");
        printf("%d", cur->data);
        first = 0;
        cur = cur->next;
    }
    if (!first) printf("\n");

    // free nodes
    cur = head;
    while (cur) {
        struct Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    return 0;
}
