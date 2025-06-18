/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int n = nums.size();
            int j = 0; // Pointer for the position to place the next non-zero element
            
            // Move non-zero elements to the front of the array
            for (int i = 0; i < n; i++) {
                if (nums[i] != 0) {
                    nums[j++] = nums[i];
                }
            }
            
            // Fill the remaining positions with zeros
            while (j < n) {
                nums[j++] = 0;
            }
        }
    };   

    //This is a two pointer approach.
    //The first pointer (i) iterates through the array, and the second pointer (j) keeps track of the position to place the next non-zero element.