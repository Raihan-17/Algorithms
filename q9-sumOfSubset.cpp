// Algorithm:

// function SubsetSum(set[], n, index, sum, target, subset):
//     if sum == target:
//         print subset
//         return

//     if index == n or sum > target:
//         return

//     // Include current element
//     subset.push(set[index])
//     SubsetSum(set, n, index + 1, sum + set[index], target, subset)

//     // Exclude current element (backtrack)
//     subset.pop()
//     SubsetSum(set, n, index + 1, sum, target, subset)


// Time Complexity: O(2^n) in worst case (all subsets)
// Space Complexity: O(n) for the recursion stack

#include <iostream>
#include <vector>
using namespace std;

void subsetSum(vector<int>& set, vector<int>& subset, int n, int index, int sum, int target) {
    // Base case: found a subset with required sum
    if (sum == target) {
        cout << "Subset: ";
        for (int x : subset) cout << x << " ";
        cout << endl;
        return;
    }

    // If index goes out of bounds or sum exceeds target
    if (index == n || sum > target) return;

    // Include current element
    subset.push_back(set[index]);
    subsetSum(set, subset, n, index + 1, sum + set[index], target);

    // Exclude current element (backtrack)
    subset.pop_back();
    subsetSum(set, subset, n, index + 1, sum, target);
}

int main() {
    vector<int> set = {3, 4, 5, 2};
    int target = 7;
    vector<int> subset;

    cout << "Subsets with sum " << target << ":\n";
    subsetSum(set, subset, set.size(), 0, 0, target);

    return 0;
}
