#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// BST Search function
int searchBST(struct Node* root, int key) {
    // Base case: not found
    if (root == NULL) {
        return 0;
    }

    // Key found
    if (root->data == key) {
        return 1;
    }

    // Search in left subtree
    if (key < root->data) {
        return searchBST(root->left, key);
    }

    // Search in right subtree
    return searchBST(root->right, key);
}

// Example usage
int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);

    int key = 7;

    if (searchBST(root, key)) {
        printf("Key found\n");
    } else {
        printf("Key not found\n");
    }

    return 0;
}