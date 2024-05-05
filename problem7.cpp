#include <iostream>

using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
    // Create a 2D array to store the subset sum possibilities
    bool dp[n + 1][sum + 1];

    // Base cases: if sum is 0, then answer is true
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; ++i)
        dp[0][i] = false;

    // Fill the dp array using dynamic programming
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (arr[i - 1] <= j) // If the current element is less than or equal to the current sum
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
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