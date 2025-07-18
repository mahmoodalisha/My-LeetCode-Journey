//second approach : recursion + memoization LIS Variant but still memoization will never work because of the given index constraint, it will give MLE and TLE how much you try, so follow bottom up
class Solution {
public:
    //mod yaha pe 0 ya 1 ho sakta hai kyun ki %2 hamesha ya toh 0 ya 1 hi dega
    int LIS(vector<int>& nums, int i, int prev, int mod){
        if(i>=nums.size()){
            return 0;
        }
        int take = 0;
        int skip = 0;

        //take
        if(prev == -1 || (nums[prev]+nums[i])%2 == mod){
            take = 1 + LIS(nums, i+1, i, mod); //element ko le liya hai toh 1+LIS kar rahe hai
        }
        //skip
        skip = LIS(nums, i+1, prev, mod);
        return max(take, skip);

    }
    int maximumLength(vector<int>& nums) {
        int maxSubsequenceLength = 0;

        maxSubsequenceLength = max(maxSubsequenceLength, LIS(nums, 0, -1, 0)); //%2 == 0 ke liye
        maxSubsequenceLength = max(maxSubsequenceLength, LIS(nums, 0, -1, 1)); //%2 == 1 ke liye

        return maxSubsequenceLength;
    }
};
//youtube: code story with mik