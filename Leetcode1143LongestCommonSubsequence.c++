
/*
Longest Common Subsequence

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
*/

class Solution {
public:
       
    int solve(string& text1, string& text2, int i, int j, vector<vector<int>>& dp){
        if(i == text1.length())
        return 0;
        if(j == text2.length())
        return 0;

        if(dp[i][j] != -1) //this is called memoization
        return dp[i][j];

        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + solve(text1,text2,i+1,j+1,dp);
        }
        else
        {
            ans = max(solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));
        }
        
       return dp[i][j] = ans;
    }   


    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int>(text2.length(), -1));
        return solve(text1, text2, 0, 0, dp);
    }
};