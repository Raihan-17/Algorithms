// Algorithm (Pseudocode Style)

// Step 1: Start
// Step 2: Input number of vertices V and edges E
// Step 3: Create adjacency matrix graph[V][V] and store weights of edges (use a large number for no direct edge)
// Step 4: Choose a starting vertex → mark it as visited
// Step 5: Initialize totalCost = 0
// Step 6: Repeat until all vertices are visited:

// Find the minimum weight edge (u, v) such that:

// u is visited

// v is not visited

// Add edge (u, v) to MST

// Mark v as visited

// Add weight of edge (u, v) to totalCost
// Step 7: Display all edges in MST and totalCost
// Step 8: Stop


// Time Complexity:
// O(V²) using adjacency matrix
// Space: O(V²) for storing the graph



#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(vector<int> &weight, vector<bool> &visited, int V) {
    int minVertex = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

void primMST(vector<vector<int>> &graph, int V) {
    vector<int> parent(V, -1);
    vector<int> weight(V, INT_MAX);
    vector<bool> visited(V, false);

    weight[0] = 0; // Start from vertex 0

    for (int i = 0; i < V - 1; i++) {
        int u = findMinVertex(weight, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < weight[v]) {
                weight[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;
    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "  weight: " << graph[i][parent[i]] << "\n";
        totalCost += graph[i][parent[i]];
    }
    cout << "Total cost of MST: " << totalCost << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph, V);
    return 0;
}
