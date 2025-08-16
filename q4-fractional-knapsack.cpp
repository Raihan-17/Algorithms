// Algorithm

// Step 1: Start
// Step 2: Input number of items n
// Step 3: For each item i (1 to n), input:
// value[i] → profit of item
// weight[i] → weight of item

// Step 4: Calculate value-to-weight ratio: ratio[i] = value[i] / weight[i]
// Step 5: Sort all items in descending order of ratio[i]
// Step 6: Input capacity of knapsack W
// Step 7: Initialize totalValue = 0
// Step 8: For each item in sorted order:

// If weight[i] <= W
// Add full item to knapsack → totalValue += value[i]
// Decrease capacity → W -= weight[i]

// Else
// Take fraction: totalValue += ratio[i] * W
// Set W = 0 and break loop

// Step 9: Display totalValue
// Step 10: Stop


// Time Complexity

// Sorting: O(n log n)
// Selection: O(n)
// Overall: O(n log n)
// Space Complexity: O(1) (if sorting in-place)


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    double value, weight;
};

bool cmp(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(int W, vector<Item> &items) {
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    for (auto &item : items) {
        if (item.weight <= W) {
            totalValue += item.value;
            W -= item.weight;
        } else {
            totalValue += (item.value / item.weight) * W;
            break;
        }
    }
    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    vector<Item> items(n);
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++)
        cin >> items[i].value >> items[i].weight;

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Maximum value: " << fractionalKnapsack(W, items) << endl;
    return 0;
}
