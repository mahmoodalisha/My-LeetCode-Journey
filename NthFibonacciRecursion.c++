#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int> &dp) {
    // Base cases
    if (n <= 1)
        return n;

    // If the value is already computed, return it
    if (dp[n] != -1)
        return dp[n];

    // Compute and store the result in dp, this is memoization
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    // Handle the edge case for n = 0
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> dp(n + 1, -1); // Initialize dp vector with -1
    cout << fib(n, dp) << endl;
    return 0;
}
