/*
1262. Greatest Sum Divisible by Three
Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

Example 1:

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
Example 2:

Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.

*/

class Solution {
public:

    int solve(int i, int remain, vector<int>& nums, vector<vector<int>>& t){
        if(i>=nums.size()){
            if(remain == 0){
                return 0; //valid path tha
            }
            return INT_MIN;
        }

        if (t[i][remain] != -1){
            return t[i][remain];
        }

        int take = nums[i]+ solve(i+1, (remain+nums[i])%3, nums, t);
        int nottake = solve(i+1, remain, nums, t);
        return t[i][remain] = max(take, nottake);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> t(n, vector<int>(3, -1)); //memoization ke liye and 3 se divide karne ke baad remainder 0, 1 ya 2 hi hota hai isiliye 3 size ka liya and -1 se initialize kiya
        return solve(0, 0, nums, t);
    }
};