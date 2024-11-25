#include <stdio.h>
#include <stdlib.h>

// Structure for an edge
struct Edge {
    int src, dest, weight;
};

// Structure for a subset used in Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to find the set of an element using path compression
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Function to do union of two subsets using rank
void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (rootX != rootY) {
        // Union by rank
        if (subsets[rootX].rank < subsets[rootY].rank) {
            subsets[rootX].parent = rootY;
        } else if (subsets[rootX].rank > subsets[rootY].rank) {
            subsets[rootY].parent = rootX;
        } else {
            subsets[rootY].parent = rootX;
            subsets[rootX].rank++;
        }
    }
}

// Comparator function to sort edges by weight
int compare(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*) a;
    struct Edge* edgeB = (struct Edge*) b;
    return edgeA->weight - edgeB->weight;
}

// Function to implement Kruskal's algorithm
void kruskal(struct Edge edges[], int V, int E) {
    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Create a subset for each vertex
    struct Subset subsets[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // MST will store the resulting edges
    struct Edge mst[V - 1];
    int mstIndex = 0;

    // Iterate over all edges and add to MST if it doesn't form a cycle
    for (int i = 0; i < E; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        if (x != y) {
            mst[mstIndex++] = edges[i];
            unionSets(subsets, x, y);
        }
    }

    // Print the MST
    printf("Minimum Spanning Tree Edges:\n");
    for (int i = 0; i < mstIndex; i++) {
        printf("%d -- %d == %d\n", mst[i].src, mst[i].dest, mst[i].weight);
    }
}

int main() {
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges

    // Edge list
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V, E);
    return 0;
}
