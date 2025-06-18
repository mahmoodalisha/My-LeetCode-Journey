class Solution {
public:
    int minDistance(char* word1, char* word2) {
        int m = strlen(word1);
        int n = strlen(word2);

        // Create a DP table with (m + 1) x (n + 1)
        int dp[m + 1][n + 1];

        // Base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i; // Deleting all characters from word1
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j; // Inserting all characters to form word2
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // No operation needed
                } else {
                    dp[i][j] = std::min(dp[i - 1][j] + 1,   // Delete
                                        std::min(dp[i][j - 1] + 1,   // Insert
                                                 dp[i - 1][j - 1] + 1)); // Replace
                }
            }
        }

        return dp[m][n]; // The result is in the bottom-right corner
    }
};