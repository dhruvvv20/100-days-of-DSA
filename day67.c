#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node** adj;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge (directed)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// DFS helper
void dfs(struct Graph* graph, int v, bool* visited, int* stack, int* top) {
    visited[v] = true;

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(graph, temp->data, visited, stack, top);
        }
        temp = temp->next;
    }

    // Push after visiting all neighbors
    stack[++(*top)] = v;
}

// Topological sort
void topoSort(struct Graph* graph) {
    bool visited[100] = {false};
    int stack[100];
    int top = -1;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited, stack, &top);
        }
    }

    printf("Topological Order: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int n, m;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    topoSort(graph);

    return 0;
}