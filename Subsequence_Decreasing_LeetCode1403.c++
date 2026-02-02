/*
Given the array nums,
obtain a subsequence of the array whose sum of elements is strictly greater than the sum of 
the non included elements in such subsequence.
*/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int>result;
        sort(nums.begin(), nums.end(), greater<int>());

        int totalsum = 0;
        int currentsum = 0;

        for(int c : nums){
            totalsum += c;
        }

        for(int x : nums){
            currentsum += x;
            result.push_back(x);

            if(currentsum > totalsum - currentsum)
            break;
        }
        return result;
    }
};