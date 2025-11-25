/*
Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other 
otherwise return false.

Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1; //index of previous 1

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                if(last != -1 && i-last-1 < k)
                return false;
                last = i;
            }
        }
        return true;
    }
};