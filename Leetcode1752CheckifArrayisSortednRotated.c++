/*Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.
Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.*/ 

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            if(nums[i]>nums[(i+1)%n]){  //What does (i + 1) % n do? Let’s say n = 5. That means valid indices are 0, 1, 2, 3, 4
            //If you’re at the last element, i = 4, then i + 1 = 5. That would go out of bounds
            //(4 + 1) % 5 = 5 % 5 = 0
            //So instead of crashing at nums[5], it wraps around to nums[0].
                count++;
            }
        }
        return count <=1;  //to return true when there is only 1 or 0 break point
    }
};