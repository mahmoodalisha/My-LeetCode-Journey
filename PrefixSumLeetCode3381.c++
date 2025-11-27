/*
3381. Maximum Subarray Sum With Length Divisible by K
You are given an array of integers nums and an integer k.
Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

Example 1:
Input: nums = [1,2], k = 1
Output: 3
Explanation:
The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.
*/

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> best(k, LLONG_MAX); 
        
        long long pref = 0;
        best[0] = 0;  // prefix sum before starting
        
        long long ans = LLONG_MIN;
        
        for (int i = 0; i < n; i++) {
            pref += nums[i];
            int mod = ((i + 1) % k + k) % k;  // mod class of length
            
            if (best[mod] != LLONG_MAX) {
                ans = max(ans, pref - best[mod]);
            }
            
            best[mod] = min(best[mod], pref);
        }
        
        return ans;
    }
};
