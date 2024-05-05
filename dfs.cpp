#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform Depth First Search (DFS) traversal
void dfs(vector<vector<int>>& graph, int start) {
    int n = graph.size(); // Number of vertices in the graph
    vector<bool> visited(n, false); // Mark all vertices as not visited

    // Create a stack for DFS
    stack<int> s;

    // Push the start vertex onto the stack and mark it as visited
    s.push(start);
    visited[start] = true;

    // Continue until the stack is empty
    while (!s.empty()) {
        // Pop a vertex from the stack and print it
        int u = s.top();
        s.pop();
        cout << u << " ";

        // Get all adjacent vertices of the popped vertex u
        // If an adjacent has not been visited, mark it visited and push it onto the stack
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
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

    cout << "DFS traversal starting from vertex 0: ";
    dfs(graph, 0); // Start DFS traversal from vertex 0
    cout << endl;

    return 0;
}