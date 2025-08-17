// algorithm in functional way:

// function NQ(col):
//     if col == N:
//         print board
//         increment count
//         return
//     for row = 0 to N-1:
//         if place(row, col) is true:
//             chess[row][col] = 1
//             NQ(col + 1)
//             chess[row][col] = 0    // backtrack

//             function place(row, col):
//     check left row, upper-left diagonal, lower-left diagonal
//     if no queen found → return true
//     else → return false

//     initialize chessboard[N][N] = 0
// count = 0
// NQ(0)
// print count


// Time & Space Complexity:

// Time: O(N!) in worst case (same as before, because each column tries N rows recursively).
// Space: O(N²) for board + recursion stack O(N).

#include <iostream>
using namespace std;

int count = 0;

// Function to check if a queen can be placed at chess[row][col]
bool place(int row, int col, int n, int chess[4][4]) {
    int r = row, c = col;
    while (r >= 0 && c >= 0) {
        if (chess[r][c] == 1)
            return false;
        r--; c--;
    }
    r = row; c = col;
    while (r < n && c >= 0) {
        if (chess[r][c] == 1)
            return false;
        r++; c--;
    }
    r = row; c = col;
    while (c >= 0) {
        if (chess[r][c] == 1)
            return false;
        c--;
    }
    return true;
}

// Recursive function to place queens
void nq(int col, int n, int chess[4][4]) {
    if (col >= n) {
        count++;
        // Optional: Print the board configuration
        cout << "Solution " << count << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << (chess[i][j] ? "Q " : ". ");
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int row = 0; row < n; row++) {
        if (place(row, col, n, chess)) {
            chess[row][col] = 1;
            nq(col + 1, n, chess);
            chess[row][col] = 0;
        }
    }
}

int main() {
    int n = 4;
    int chess[4][4] = {0};
    nq(0, n, chess);
    cout << "Total solutions: " << count << endl;
    return 0;
}