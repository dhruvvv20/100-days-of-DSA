#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node* head = NULL;
    struct Node* temp = NULL;
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    int key;
    scanf("%d", &key);
    // Delete first occurrence of key
    if(head != NULL && head->data == key) {
        struct Node* toDelete = head;
        head = head->next;
        free(toDelete);
    } else {
        struct Node* prev = NULL;
        struct Node* curr = head;
        while(curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        if(curr != NULL) {
            prev->next = curr->next;
            free(curr);
        }
    }
    // Print the list
    printList(head);
    // Free memory
    freeList(head);
    return 0;
}
