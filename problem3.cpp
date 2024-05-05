#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int editDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    // Create a 2D array to store the edit distances
    int dp[m + 1][n + 1];

    // Base case: If one of the strings is empty, the edit distance is the length of the other string
    for (int i = 0; i <= m; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= n; ++j)
        dp[0][j] = j;

    // Fill the dp array using dynamic programming
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                // If characters are equal, no operation is needed
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Otherwise, take the minimum of three operations (insertion, deletion, or substitution) and add 1
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }

    // Return the bottom-right cell of the dp array, which contains the edit distance
    return dp[m][n];
}

int main() {
    string word1, word2;
    cout << "Enter the first word: ";
    cin >> word1;
    cout << "Enter the second word: ";
    cin >> word2;

    int distance = editDistance(word1, word2);
    cout << "Edit distance between \"" << word1 << "\" and \"" << word2 << "\": " << distance << endl;

    return 0;
}