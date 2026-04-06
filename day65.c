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

// Add edge (undirected)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}

// DFS cycle detection
bool dfs(struct Graph* graph, int v, bool* visited, int parent) {
    visited[v] = true;

    struct Node* temp = graph->adj[v];
    while (temp) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(graph, neighbor, visited, v))
                return true;
        }
        else if (neighbor != parent) {
            return true; // cycle found
        }

        temp = temp->next;
    }

    return false;
}

// Main function
int main() {
    int n, m;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    printf("Enter edges:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    bool visited[100] = {false};
    bool hasCycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, -1)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}