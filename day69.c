#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Node for adjacency list
struct Node {
    int v, weight;
    struct Node* next;
};

// Graph
struct Graph {
    int V;
    struct Node** adj;
};

// Heap node
struct HeapNode {
    int v, dist;
};

// Min Heap
struct MinHeap {
    int size;
    struct HeapNode* arr[1000];
};

// Create node
struct Node* createNode(int v, int w) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->v = v;
    node->weight = w;
    node->next = NULL;
    return node;
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

// Add edge
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = graph->adj[u];
    graph->adj[u] = node;
}

// Swap heap nodes
void swap(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < heap->size && heap->arr[left]->dist < heap->arr[smallest]->dist)
        smallest = left;

    if (right < heap->size && heap->arr[right]->dist < heap->arr[smallest]->dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

// Extract min
struct HeapNode* extractMin(struct MinHeap* heap) {
    if (heap->size == 0) return NULL;

    struct HeapNode* root = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    heapify(heap, 0);

    return root;
}

// Insert into heap
void insertHeap(struct MinHeap* heap, int v, int dist) {
    int i = heap->size++;
    heap->arr[i] = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    heap->arr[i]->v = v;
    heap->arr[i]->dist = dist;

    // Fix heap property
    while (i && heap->arr[(i-1)/2]->dist > heap->arr[i]->dist) {
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Dijkstra using PQ
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[100];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    struct MinHeap heap;
    heap.size = 0;

    insertHeap(&heap, src, 0);

    while (heap.size > 0) {
        struct HeapNode* minNode = extractMin(&heap);
        int u = minNode->v;

        struct Node* temp = graph->adj[u];

        while (temp) {
            int v = temp->v;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d -> %d\n", i, dist[i]);
    }
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 2, 3, 4);

    dijkstra(graph, 0);

    return 0;
}