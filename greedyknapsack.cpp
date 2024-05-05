#include <iostream>

using namespace std;

// Structure to represent items
struct Item {
    int value;
    int weight;
};

// Function to compare items based on their value-to-weight ratio
bool compare(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2; // Sort in non-decreasing order of value-to-weight ratio
}

// Function to sort items based on their value-to-weight ratio (bubble sort)
void bubbleSort(Item arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!compare(arr[j], arr[j + 1])) {
                // Swap items if value-to-weight ratio is not in non-decreasing order
                Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to solve the Knapsack Problem using Greedy Algorithm
double knapsackGreedy(Item arr[], int n, int capacity) {
    // Sort items based on their value-to-weight ratio
    bubbleSort(arr, n);

    double totalValue = 0.0;
    int currentWeight = 0;

    // Iterate through the sorted items and add them to the knapsack
    for (int i = 0; i < n; ++i) {
        if (currentWeight + arr[i].weight <= capacity) {
            // Add the entire item if it can fit into the knapsack
            totalValue += arr[i].value;
            currentWeight += arr[i].weight;
        } else {
            // Otherwise, add a fractional part of the item to maximize value
            int remainingWeight = capacity - currentWeight;
            totalValue += (double)arr[i].value / arr[i].weight * remainingWeight;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    double maxValue = knapsackGreedy(items, n, capacity);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}