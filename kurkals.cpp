#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Comparator function for sorting edges based on their weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find the parent of a vertex using path compression technique
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets using union by rank
void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the Minimum Spanning Tree (MST) using Kruskal's algorithm
void kruskal(vector<Edge>& edges, int V) {
    // Sort all the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Allocate memory for subsets
    Subset* subsets = new Subset[V];
    
    // Create V subsets with single elements
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Initialize variables to store MST and total weight
    vector<Edge> MST;
    int totalWeight = 0;

    // Iterate through all edges in sorted order
    for (Edge edge : edges) {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        // If including this edge does not cause a cycle, add it to MST
        if (x != y) {
            MST.push_back(edge);
            Union(subsets, x, y);
            totalWeight += edge.weight;
        }
    }

    // Print the MST and total weight
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (Edge edge : MST) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
    cout << "Total Weight of Minimum Spanning Tree: " << totalWeight << endl;

    delete[] subsets; // Free memory allocated for subsets
}

int main() {
    // Example graph represented as a vector of edges
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int V = 4; // Number of vertices in the graph

    // Call the kruskal function to find the MST
    kruskal(edges, V);

    return 0;
}