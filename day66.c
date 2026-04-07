#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node for adjacency list
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

// DFS for cycle detection
bool dfs(struct Graph* graph, int v, int* state) {
    state[v] = 1; // visiting

    struct Node* temp = graph->adj[v];
    while (temp) {
        int neighbor = temp->data;

        if (state[neighbor] == 1) {
            return true; // cycle found
        }

        if (state[neighbor] == 0) {
            if (dfs(graph, neighbor, state))
                return true;
        }

        temp = temp->next;
    }

    state[v] = 2; // done
    return false;
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

    int state[100] = {0}; // 0 = unvisited

    bool hasCycle = false;

    for (int i = 0; i < n; i++) {
        if (state[i] == 0) {
            if (dfs(graph, i, state)) {
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