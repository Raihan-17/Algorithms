// Algorithm:

// function graphColoring(graph, m, colors, v):
//     if v == V:
//         print colors  // all vertices colored successfully
//         return true

//     for c = 1 to m:
//         if isSafe(graph, v, colors, c):
//             colors[v] = c
//             if graphColoring(graph, m, colors, v + 1):
//                 return true
//             colors[v] = 0   // backtrack

//     return false

// function isSafe(graph, v, colors, c):
//     for every neighbor u of v:
//         if colors[u] == c:
//             return false
//     return true

// Time Complexity: O(m^V) in worst case (m colors for V vertices)
// Space Complexity: O(V) for colors array



#include <iostream>
using namespace std;

#define V 4   // number of vertices

// Check if assigning color c to vertex v is safe
bool isSafe(int graph[V][V], int colors[V], int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && colors[i] == c)
            return false;
    }
    return true;
}

// Recursive function to assign colors
bool graphColoring(int graph[V][V], int m, int colors[V], int v) {
    if (v == V) {  // all vertices are assigned
        cout << "Solution exists: Coloring is -> ";
        for (int i = 0; i < V; i++)
            cout << colors[i] << " ";
        cout << endl;
        return true;
    }

    for (int c = 1; c <= m; c++) {  // try all colors
        if (isSafe(graph, colors, v, c)) {
            colors[v] = c;
            if (graphColoring(graph, m, colors, v + 1))
                return true;
            colors[v] = 0; // backtrack
        }
    }

    return false;
}

int main() {
    // Example: 4-vertex cycle graph
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // number of colors
    int colors[V] = {0};

    if (!graphColoring(graph, m, colors, 0))
        cout << "No solution exists." << endl;

    return 0;
}
