#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define V 4

// Find the vertex with the minimum distance value
int minDistance(int dist[], int visited[]) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's Algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V], visited[V];

    // Initialize all distances as infinite and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Dijkstra's Algorithm Distances:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Distance %d\n", i, dist[i]);
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 10, 0, 30},
        {10, 0, 50, 0},
        {0, 50, 0, 20},
        {30, 0, 20, 0}
    };

    int src = 0; // Starting vertex
    printf("Source Vertex: %d\n", src);
    dijkstra(graph, src);

    return 0;
}
