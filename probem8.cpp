#include <iostream>

using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
    // Base cases:
    // If sum is 0, then an empty subset can achieve this sum
    if (sum == 0)
        return true;
    // If n is 0 and sum is non-zero, then no subset can achieve this sum
    if (n == 0)
        return false;

    // If the last element is greater than the sum, it can't be included in the subset
    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum);

    // Check if sum can be obtained by including or excluding the last element
    return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 9;

    if (isSubsetSum(arr, n, sum))
        cout << "Subset with sum " << sum << " exists." << endl;
    else
        cout << "Subset with sum " << sum << " does not exist." << endl;

    return 0;
}