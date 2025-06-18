class Solution {
    public:
        const int MOD = 1e9 + 7;
        int numTilings(int n) {
            if (n == 1) return 1;
            if (n == 2) return 2;
            if (n == 3) return 5;  // Fixed base case for n = 3
    
            vector<long long> dp(n + 1);  // dp is a vector (array) of size n + 1
            dp[0] = 1;  // Nothing but base cases for dp[n]
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 5;  // Base case for dp[3]
    
            // Now the recursive formula (dp formula)
            for (int i = 4; i <= n; i++) {  // Fixing loop to include i = n
                dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
            }
    
            return dp[n];
        }
    };
    