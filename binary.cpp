// Algorithm for the code:

// Start with two pointers: low = 0 and high = n - 1 (where n is array size).

// While low ≤ high:

// Find the middle index: mid = (low + high) / 2

// If array[mid] == target → element found → return position.

// Else if array[mid] < target → search in the right half → low = mid + 1.

// Else → search in the left half → high = mid - 1.

// If loop ends → element is not found.



// Time Complexity: O(log n)
// Space Complexity: O(1)




#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoids overflow
        if (arr[mid] == key)
            return mid; // Found
        else if (arr[mid] < key)
            low = mid + 1; // Search right half
        else
            high = mid - 1; // Search left half
    }
    return -1; // Not found
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements in sorted order:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
