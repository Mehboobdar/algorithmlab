#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int dest, weight;
};

// Structure to represent a node in the priority queue
struct PQNode {
    int vertex, key;
};

// Comparator function for the priority queue
struct CompareNode {
    bool operator()(const PQNode& a, const PQNode& b) const {
        return a.key > b.key; // Sort nodes by key (minimum key at the top)
    }
};

// Function to find the Minimum Spanning Tree (MST) using Prim's algorithm
void primMST(vector<vector<Edge>>& graph, int V) {
    vector<int> parent(V, -1); // Array to store the parent of each vertex in MST
    vector<int> key(V, INT_MAX); // Array to store the key value of each vertex
    vector<bool> inMST(V, false); // Array to track whether a vertex is in the MST or not

    priority_queue<PQNode, vector<PQNode>, CompareNode> pq; // Min-heap priority queue

    // Start with vertex 0
    key[0] = 0; // Set key value of source vertex to 0
    pq.push({0, 0}); // Push the source vertex to the priority queue

    // Loop until all vertices are included in MST
    while (!pq.empty()) {
        int u = pq.top().vertex; // Extract vertex with minimum key
        pq.pop();
        inMST[u] = true; // Include the vertex in MST

        // Update key values of adjacent vertices and push them to the priority queue
        for (Edge& edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({v, key[v]});
            }
        }
    }

    // Print the edges of the MST and the total weight
    int totalWeight = 0;
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
        totalWeight += key[i];
    }
    cout << "Total Weight of Minimum Spanning Tree: " << totalWeight << endl;
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<Edge>> graph = {
        {{1, 10}, {2, 6}, {3, 5}}, // Adjacent vertices of vertex 0
        {{0, 10}, {3, 15}},         // Adjacent vertices of vertex 1
        {{0, 6}, {3, 4}},           // Adjacent vertices of vertex 2
        {{0, 5}, {1, 15}, {2, 4}}   // Adjacent vertices of vertex 3
    };
    int V = graph.size(); // Number of vertices in the graph

    // Call the primMST function to find the MST
    primMST(graph, V);

    return 0;
}