#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Adjacency list node
struct Node {
    int v, w;
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
    node->w = w;
    node->next = NULL;
    return node;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc((V + 1) * sizeof(struct Node*));

    for (int i = 1; i <= V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* node = createNode(v, w);
    node->next = graph->adj[u];
    graph->adj[u] = node;

    node = createNode(u, w); // undirected
    node->next = graph->adj[v];
    graph->adj[v] = node;
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
    int l = 2*i + 1, r = 2*i + 2;

    if (l < heap->size && heap->arr[l]->dist < heap->arr[smallest]->dist)
        smallest = l;
    if (r < heap->size && heap->arr[r]->dist < heap->arr[smallest]->dist)
        smallest = r;

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

// Insert heap
void insertHeap(struct MinHeap* heap, int v, int dist) {
    int i = heap->size++;
    heap->arr[i] = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    heap->arr[i]->v = v;
    heap->arr[i]->dist = dist;

    while (i && heap->arr[(i-1)/2]->dist > heap->arr[i]->dist) {
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Dijkstra
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[101];

    for (int i = 1; i <= V; i++)
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
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insertHeap(&heap, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    // Print result
    for (int i = 1; i <= V; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}