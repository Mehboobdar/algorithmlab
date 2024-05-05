#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform Breadth First Search (BFS) traversal
void bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size(); // Number of vertices in the graph
    vector<bool> visited(n, false); // Mark all vertices as not visited

    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    q.push(start);

    // Continue until the queue is empty
    while (!q.empty()) {
        // Dequeue a vertex from the queue and print it
        int u = q.front();
        q.pop();
        cout << u << " ";

        // Get all adjacent vertices of the dequeued vertex u
        // If an adjacent has not been visited, mark it visited and enqueue it
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},     // Adjacent vertices of vertex 0
        {0, 3, 4},  // Adjacent vertices of vertex 1
        {0, 4},     // Adjacent vertices of vertex 2
        {1},        // Adjacent vertices of vertex 3
        {1, 2}      // Adjacent vertices of vertex 4
    };

    cout << "BFS traversal starting from vertex 0: ";
    bfs(graph, 0); // Start BFS traversal from vertex 0
    cout << endl;

    return 0;
}