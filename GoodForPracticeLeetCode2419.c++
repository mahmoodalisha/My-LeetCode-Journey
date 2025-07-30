class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end()); //finds the maximum value in the nums vector
        int maxLen = 0;
        int currLen = 0;

        for(int num : nums){
            if(num == maxVal){
                currLen++;
                maxLen = max(maxLen, currLen);
            }
            else {
                currLen = 0;
            }
        }
        return maxLen;
    }
};
/* 
nums = {1, 3, 7, 7, 2, 7}; then int maxVal = *max_element(nums.begin(), nums.end());
This sets maxVal = 7

*/