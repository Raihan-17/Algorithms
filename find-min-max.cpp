// Algorithm Steps:

// Base case 1: If there’s only one element → that element is both min & max.

// Base case 2: If there are two elements → compare them once, assign min & max.

// Otherwise:

// Find mid index.

// Recursively get min & max for left half.

// Recursively get min & max for right half.

// Final min = min(leftMin, rightMin)
// Final max = max(leftMax, rightMax).


// time Complexity: O(n)
// space Complexity: O(log n) due to recursion stack

#include <iostream>
#include <utility> // for pair
using namespace std;

pair<int, int> findmaxmin(int arr[], int low, int high) {
    // Base case: one element
    if (low == high) {
        return { arr[low], arr[high] };
    }

    // Base case: two elements
    if (high == low + 1) {
        if (arr[low] > arr[high])
            return { arr[low], arr[high] }; // max, min
        else
            return { arr[high], arr[low] };
    }

    // Recursive case
    int mid = (low + high) / 2;
    pair<int, int> left  = findmaxmin(arr, low, mid);
    pair<int, int> right = findmaxmin(arr, mid + 1, high);

    int maxelement = max(left.first, right.first);
    int minelement = min(left.second, right.second);

    return { maxelement, minelement };
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    pair<int, int> ans = findmaxmin(arr, 0, n - 1);

    cout << "Maximum: " << ans.first << endl;
    cout << "Minimum: " << ans.second << endl;

    return 0;
}
