#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) front = 0;

    queue[++rear] = value;
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int n, value;

    scanf("%d", &n);

    // Enqueue n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    // Display queue
    display();

    return 0;
}