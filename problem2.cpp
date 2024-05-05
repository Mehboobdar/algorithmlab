#include <iostream>

using namespace std;

const int INF = 1e9; // A large constant representing infinity

int getMinCoins(int n) {
    int dp[n + 1]; // dp[i] stores the minimum number of coins needed for amount i
    int coins[] = {1, 3, 4};   // available denominations

    // Base case: 0 coins needed for amount 0
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = INF; // Initialize dp[i] to infinity

        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the amount to make change for: ";
    cin >> n;

    int minCoins = getMinCoins(n);
    cout << "Minimum number of coins needed: " << minCoins << endl;

    return 0;
}