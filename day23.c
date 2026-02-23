#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* merge(struct Node* l1, struct Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    struct Node* result;
    if (l1->data <= l2->data) {
        result = l1;
        result->next = merge(l1->next, l2);
    } else {
        result = l2;
        result->next = merge(l1, l2->next);
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* head1 = NULL;
    struct Node* temp = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head1 == NULL) {
            head1 = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    int m;
    scanf("%d", &m);
    struct Node* head2 = NULL;
    temp = NULL;
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if (head2 == NULL) {
            head2 = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    struct Node* merged = merge(head1, head2);
    temp = merged;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    // Free memory
    temp = merged;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    return 0;
}
