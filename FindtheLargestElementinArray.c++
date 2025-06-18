/*Given an array of integers nums, return the value of the largest element in the array
Input: nums = [3, 3, 6, 1]
Output: 6
Explanation: The largest element in array is 6 */

//follow the optimal approach TC O(n) SC O(1)

class Solution {
    public:
        int largestElement(vector<int>& nums) {
            int largest = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > largest) {
                    largest = nums[i];
                }
            }
            return largest;
        }
    };