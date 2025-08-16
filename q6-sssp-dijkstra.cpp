// Algorithm (Pseudocode):

// Step 1: Start
// Step 2: Input number of vertices V and adjacency matrix graph[V][V] (hardcoded)
// Step 3: Input source vertex src (hardcoded)
// Step 4: Initialize:
// dist[] = INF for all vertices except src (set to 0)
// visited[] = false for all vertices

// Step 5: Repeat for V-1 times:
// Find the unvisited vertex with the smallest dist[] value → u
// Mark u as visited
// For each neighbor v of u:
// If graph[u][v] != 0 and visited[v] == false:
// If dist[u] + graph[u][v] < dist[v] → update dist[v]

// Step 6: Display dist[] array as shortest distances from src
// Step 7: Stop


// Time Complexity:
// O(V²) with adjacency matrix
// O((V+E) log V) with priority queue (not used here for simplicity)

// Space: O(V²) for matrix + O(V) for arrays

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDistance(vector<int> &dist, vector<bool> &visited, int V) {
    int minVal = INT_MAX, minIndex = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= minVal) {
            minVal = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(vector<vector<int>> &graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    };
    int src = 0;

    dijkstra(graph, src, V);
    return 0;
}

