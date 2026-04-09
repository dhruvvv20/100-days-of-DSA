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

// Add directed edge
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// Topological sort using BFS (Kahn’s)
void topoSort(struct Graph* graph) {
    int V = graph->V;

    int indegree[100] = {0};

    // Step 1: Calculate indegree
    for (int i = 0; i < V; i++) {
        struct Node* temp = graph->adj[i];
        while (temp) {
            indegree[temp->data]++;
            temp = temp->next;
        }
    }

    // Queue
    int queue[100];
    int front = 0, rear = 0;

    // Step 2: Push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // Step 3: BFS
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        struct Node* temp = graph->adj[node];
        while (temp) {
            int neighbor = temp->data;
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }

    // Step 4: Cycle check
    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
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