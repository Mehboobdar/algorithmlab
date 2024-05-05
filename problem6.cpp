#include <iostream>

using namespace std;

const int MAXN = 1001;

int minJumpsToEnd(int nums[], int n) {
    if (n == 0 || nums[0] == 0) // If the array is empty or the first element is 0, cannot reach the end
        return MAXN;

    int jumps[MAXN]; // Array to store minimum jumps needed
    jumps[0] = 0; // Minimum number of jumps needed to reach the first position is 0

    for (int i = 1; i < n; ++i) {
        jumps[i] = MAXN; // Initialize jumps[i] with a large value

        for (int j = 0; j < i; ++j) {
            if (j + nums[j] >= i) { // If we can reach position i from position j
                if (jumps[j] != MAXN) // If jumps[j] is reachable
                    jumps[i] = min(jumps[i], jumps[j] + 1); // Update jumps[i] with minimum jumps needed
            }
        }
    }

    return jumps[n - 1];
}

int main() {
    int nums[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1}; // Example array
    int n = sizeof(nums) / sizeof(nums[0]); // Calculate the size of the array

    int minJumps = minJumpsToEnd(nums, n);
    if (minJumps != MAXN)
        cout << "Minimum number of jumps needed: " << minJumps << endl;
    else
        cout << "Cannot reach the end of the array." << endl;

    return 0;
}