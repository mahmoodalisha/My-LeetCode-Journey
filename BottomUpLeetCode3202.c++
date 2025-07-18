class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(k, vector<int>(n,1)); //k rows hain Har row mein n elements hain Har element ki value initially 1 hai.
        int maxSubsequenceLength = 1;

        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                int mod = (nums[i]+nums[j])%k;

                dp[mod][i] = max(dp[mod][i], 1+dp[mod][j]);
                maxSubsequenceLength = max(maxSubsequenceLength, dp[mod][i]);
            }
        }
        return maxSubsequenceLength;
    }
};
//youtube: code story with mik