/*
The prefix sum is the cumulative sum of elements from the start up to the current index.
Here, we compute prefixSum as we iterate, and the right sum is derived as totalSum - prefixSum.
By maintaining a running prefix sum, we avoid recomputing the sum of the left subarray for every split, making it O(n) instead of O(n²).
*/


class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalsum = 0;
        int count = 0;

        for(int num : nums){
            totalsum += num;
        }
        long long prefixSum = 0;
        for(int i = 0; i<nums.size()-1; i++){
            prefixSum += nums[i];
            long long rightsum = totalsum-prefixSum;

            if(prefixSum >= rightsum){
                count++;
            }
        }
        return count;
    }
};