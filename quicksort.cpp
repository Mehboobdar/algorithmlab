#include <iostream>

using namespace std;

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    // Partitioning loop
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i; // Move the index of the smaller element
            swap(arr[i], arr[j]); // Swap arr[i] and arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // Swap arr[i+1] and arr[high] (pivot)
    return i + 1; // Return the pivot index
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array, pivot is at index pi
        int pi = partition(arr, low, high);

        // Sort the elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}