#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOperations(int n) {
    vector<int> dp(n + 1, 0); // dp[i] stores the minimum number of operations needed to reach number i

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1; // At minimum, we can always add 1 to get to the next number

        if (i % 2 == 0) // If i is divisible by 2, we can either reach i by multiplying i/2 by 2
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) // If i is divisible by 3, we can either reach i by multiplying i/3 by 3
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    int minOps = minOperations(n);
    cout << "Minimum number of operations needed to obtain " << n << ": " << minOps << endl;

    return 0;
}