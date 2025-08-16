// Algorithm:

// Step 1: Start
// Step 2: Input number of elements n
// Step 3: Input array A[1…n] in unsorted form
// Step 4: Copy A into two arrays: B and Q
// Step 5:
// Bubble Sort on B
// Repeat i = 0 to n-2
//     Repeat j = 0 to n-i-2
//         If B[j] > B[j+1], swap them
// Record the execution time for Bubble Sort
// Step 6:
// Quick Sort on Q
// QuickSort(Q, low, high):
//     If low < high
//         Partition Q into two subarrays around a pivot
//    Recursively QuickSort left subarray
//    Recursively QuickSort right subarray

// Record the execution time for Quick Sort
// Step 7: Display both times and compare
// Step 8: Stop


// Time Complexity:

// Bubble Sort: Best O(n), Worst/Average O(n²)
// Quick Sort: Best/Average O(n log n), Worst O(n²)
// Space: Bubble O(1), Quick O(log n) (stack space)


#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> arr1 = arr, arr2 = arr;

    clock_t start = clock();
    bubbleSort(arr1);
    clock_t end = clock();
    cout << "Bubble Sort time: " << double(end - start) / CLOCKS_PER_SEC << " sec\n";

    start = clock();
    quickSort(arr2, 0, n-1);
    end = clock();
    cout << "Quick Sort time: " << double(end - start) / CLOCKS_PER_SEC << " sec\n";
// Compare times
    if (double(end - start) < double(end - start))
        cout << "Quick Sort is faster than Bubble Sort.\n";
    else
        cout << "Bubble Sort is faster than Quick Sort.\n";

    return 0;
}
