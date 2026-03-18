#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for level order
struct Node* queue[100];
int front = 0, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (front <= rear) {
        struct Node* temp = dequeue();

        printf("%d ", temp->data);

        if (temp->left)
            enqueue(temp->left);

        if (temp->right)
            enqueue(temp->right);
    }
}

int main() {
    // Example tree:
    //        1
    //      /   \
    //     2     3
    //    / \   / \
    //   4  5  6   7

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    levelOrder(root);

    return 0;
}