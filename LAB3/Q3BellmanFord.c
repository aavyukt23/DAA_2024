#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define V 4
#define E 4

// Bellman-Ford Algorithm
void bellmanFord(int edges[E][3], int src) {
    int dist[V];

    // Initialize distances from src to all vertices as infinite
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // Relax all edges |V|-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printf("Bellman-Ford Algorithm Distances:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d -> Distance %d\n", i, dist[i]);
    }
}

int main() {
    // Example graph represented as an edge list (u, v, weight)
    int edges[E][3] = {
        {0, 1, -1},  // Edge from vertex 0 to 1 with weight -1
        {0, 2, 4},   // Edge from vertex 0 to 2 with weight 4
        {1, 2, 3},   // Edge from vertex 1 to 2 with weight 3
        {1, 3, 2},   // Edge from vertex 1 to 3 with weight 2
        {3, 1, 1},   // Edge from vertex 3 to 1 with weight 1
        {3, 2, 5}    // Edge from vertex 3 to 2 with weight 5
    };

    int src = 0; // Starting vertex (source)
    printf("Source Vertex: %d\n", src);
    bellmanFord(edges, src);

    return 0;
}
