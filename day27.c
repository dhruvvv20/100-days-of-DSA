
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* create_node(int val) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = val;
    node->next = NULL;
    return node;
}
void insert_end(struct Node **head_ref, int val) {
    struct Node *new_node = create_node(val);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node *cur = *head_ref;
    while (cur->next)        cur = cur->next;
    cur->next = new_node;
}
int get_length(struct Node *head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}
struct Node* find_intersection(struct Node *head1, struct Node *head2) {
    int len1 = get_length(head1);
    int len2 = get_length(head2);
    struct Node *longer = len1 > len2 ? head1 : head2;
    struct Node *shorter = len1 > len2 ? head2 : head1;
    int diff = abs(len1 - len2);
    for (int i = 0; i < diff; ++i) {
        if (longer == NULL) return NULL;
        longer = longer->next;
    }
    while (longer && shorter) {
        if (longer == shorter) return longer;
        longer = longer->next;
        shorter = shorter->next;
    }
    return NULL;
}
int main() {
    int n, m;
    if (scanf("%d", &n) != 1) return 0;
    struct Node *head1 = NULL;
    for (int i = 0; i < n; ++i) {
        int x;
        if (scanf("%d", &x) != 1) x = 0;
        insert_end(&head1, x);
    }
    if (scanf("%d", &m) != 1) return 0;
    struct Node *head2 = NULL;
    for (int i = 0; i < m; ++i) {
        int x;
        if (scanf("%d", &x) != 1) x = 0;
        insert_end(&head2, x);
    }
    struct Node *intersection = find_intersection(head1, head2);
    if (intersection) {
        printf("%d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }
    // free nodes
    struct Node *cur;
    cur = head1;
    while (cur) {
        struct Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    cur = head2;
    while (cur) {
        struct Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    return 0;
}