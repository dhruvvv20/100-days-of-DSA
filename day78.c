#include <stdio.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[101][101];

    // Initialize with large value
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[101];
    int visited[101] = {0};

    // Initialize keys
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
    }

    key[1] = 0; // start from node 1

    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;

        // Find minimum key vertex
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || key[j] < key[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // Update neighbors
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !visited[v]) {
                if (graph[u][v] < key[v]) {
                    key[v] = graph[u][v];
                }
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}