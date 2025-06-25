class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currSubSum = nums[0];
        int maxSubSum = nums[0];

        //kadane's algo for finding max subarray sum
        for(int i = 1; i<n; i++){
            currSubSum = max(nums[i], currSubSum+nums[i]); //this formula and dry run in my DSA copy
            maxSubSum = max(maxSubSum, currSubSum);
        }

        int minSubSum = nums[0];
        currSubSum = nums[0];//re initiate karo kyun ki update ho gaya hai
        //kadane's algo for finding min subarray sum
        for(int i = 1; i<n; i++){
            currSubSum = min(nums[i], currSubSum+nums[i]); //this formula and dry run in my DSA copy
            minSubSum = min(minSubSum, currSubSum);
        }
        return max(maxSubSum, abs(minSubSum));
    }
};