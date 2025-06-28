//Approach1 Recursion + memoization
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        // Step 1: Find the LCS (Longest Common Subsequence)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 2: Build the Shortest Common Supersequence using LCS
        string result = "";
        int i = m, j = n;

        while(i > 0 && j > 0) {
            if(str1[i - 1] == str2[j - 1]) {
                result += str1[i - 1];
                i--;
                j--;
            } else if(dp[i - 1][j] > dp[i][j - 1]) {
                result += str1[i - 1];
                i--;
            } else {
                result += str2[j - 1];
                j--;
            }
        }

        // Add remaining characters
        while(i > 0) {
            result += str1[i - 1];
            i--;
        }
        while(j > 0) {
            result += str2[j - 1];
            j--;
        }

        // Since we built result in reverse, reverse it back
        reverse(result.begin(), result.end());
        return result;
    }
};
