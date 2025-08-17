// Algorithm (Pseudocode Style):

// Step 1: Start
// Step 2: Input number of vertices V and adjacency matrix graph[V][V] (hardcoded in our case)

// If no direct edge between i and j, set graph[i][j] = INF (large value)
// Step 3: Initialize distance matrix dist = graph
// Step 4: For each intermediate vertex k = 0 … V-1:

// For each vertex i = 0 … V-1:
// For each vertex j = 0 … V-1:

// If dist[i][k] + dist[k][j] < dist[i][j] → update
// dist[i][j] = dist[i][k] + dist[k][j]
// Step 5: After all iterations, dist[i][j] contains the shortest distance from i to j
// Step 6: Print the final dist[][] matrix
// Step 7: Stop

// Time & Space Complexity:

// Time: O(V³) (triple nested loop)
// Space: O(V²) (distance matrix)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define INF 99999

void floydWarshall(vector<vector<int>> graph, int V) {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; k++) {          // intermediate vertex
        for (int i = 0; i < V; i++) {      // source vertex
            for (int j = 0; j < V; j++) {  // destination vertex
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "All Pairs Shortest Path Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> graph = {
        {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph, V);
    return 0;
}
