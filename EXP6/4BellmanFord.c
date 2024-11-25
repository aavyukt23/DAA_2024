#include <stdio.h>
#include <limits.h>

// Structure for an edge
struct Edge {
    int src, dest, weight;
};

// Function to run the Bellman-Ford algorithm
void bellmanFord(struct Edge edges[], int V, int E, int src) {
    int dist[V];
    
    // Initialize the distance to all vertices as infinity
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;  // Distance to source is 0

    // Relax all edges (V - 1) times
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[edges[j].src] != INT_MAX && dist[edges[j].src] + edges[j].weight < dist[edges[j].dest]) {
                dist[edges[j].dest] = dist[edges[j].src] + edges[j].weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; i++) {
        if (dist[edges[i].src] != INT_MAX && dist[edges[i].src] + edges[i].weight < dist[edges[i].dest]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print the shortest distances from the source
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    // Number of vertices and edges
    int V = 5, E = 8;

    // Edge list
    struct Edge edges[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {2, 3, 5},
        {2, 4, 1},
        {3, 4, -3}
    };

    // Run Bellman-Ford algorithm from vertex 0 (source)
    bellmanFord(edges, V, E, 0);

    return 0;
}
