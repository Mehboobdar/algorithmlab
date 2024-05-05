#include <iostream>

using namespace std;

const int MAXN = 101;

int dp[MAXN][MAXN][MAXN]; // 3D array to store lengths of common subsequences

int longestCommonSubsequenceLength(int seq1[], int m, int seq2[], int n, int seq3[], int p) {
    // Fill the dp array using dynamic programming
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= p; ++k) {
                if (i == 0 || j == 0 || k == 0) {
                    dp[i][j][k] = 0; // Base case: if any sequence is empty, no common subsequence possible
                } else if (seq1[i - 1] == seq2[j - 1] && seq1[i - 1] == seq3[k - 1]) {
                    // If current elements of all sequences match, add 1 to the length of the common subsequence
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    // If current elements don't match, take the maximum of the lengths of common subsequences
                    // obtained by excluding each sequence element one by one
                    dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
                }
            }
        }
    }

    // Return the length of the longest common subsequence
    return dp[m][n][p];
}

int main() {
    int seq1[] = {1, 2, 3, 4, 5};
    int m = 5;
    int seq2[] = {2, 4, 5, 6};
    int n = 4;
    int seq3[] = {1, 2, 5, 6};
    int p = 4;

    int length = longestCommonSubsequenceLength(seq1, m, seq2, n, seq3, p);
    cout << "Length of the longest common subsequence: " << length << endl;

    return 0;
}