#include <stdio.h>
#include <limits.h>

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Prim's algorithm
void prim(int graph[][5], int V) {
    int parent[V];  // Array to store the MST
    int key[V];     // Key values to select minimum weight edge
    int mstSet[V];  // To represent vertices included in MST

    // Initialize all keys as infinite and mstSet as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Start with the first vertex
    key[0] = 0;
    parent[0] = -1;  // First node has no parent

    // Construct the MST
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet processed
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;  // Include vertex u in the MST

        // Update key values and parent index of adjacent vertices
        for (int v = 0; v < V; v++) {
            // Update the key value of adjacent vertices
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    // Graph represented as an adjacency matrix
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(graph, 5);
    return 0;
}
