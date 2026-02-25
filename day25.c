
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *create_node(int val) {
	Node *n = malloc(sizeof(Node));
	if (!n) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	n->data = val;
	n->next = NULL;
	return n;
}

void append(Node **head, int val) {
	Node *n = create_node(val);
	if (*head == NULL) {
		*head = n;
		return;
	}
	Node *cur = *head;
	while (cur->next) cur = cur->next;
	cur->next = n;
}

int count_occurrences(Node *head, int key) {
	int count = 0;
	for (Node *cur = head; cur != NULL; cur = cur->next)
		if (cur->data == key) count++;
	return count;
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) return 0;

	Node *head = NULL;
	for (int i = 0; i < n; ++i) {
		int v;
		if (scanf("%d", &v) != 1) v = 0;
		append(&head, v);
	}

	int key;
	if (scanf("%d", &key) != 1) key = 0;

	int result = count_occurrences(head, key);
	printf("%d\n", result);

	Node *cur = head;
	while (cur) {
		Node *tmp = cur;
		cur = cur->next;
		free(tmp);
	}

	return 0;
}

