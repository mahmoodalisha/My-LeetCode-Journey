/*Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.
Input: nums = [8, 8, 7, 6, 5]
Output: 7
Explanation: The largest value in nums is 8, the second largest is 7 

Input: nums = [10, 10, 10, 10, 10]
Output: -1
Explanation: The only value in nums is 10, so there is no second largest value, thus -1 is returned
*/

class Solution {
    public:
        int secondLargestElement(vector<int>& nums) {
            int largest = INT_MIN;
            int secondlargest = INT_MIN;
            for (int i = 0; i<nums.size(); i++){
                if(nums[i]> largest){
                    secondlargest = largest;
                    largest = nums[i];
                }
                else if (nums[i] > secondlargest && nums[i] != largest){
                    secondlargest = nums[i];
                }
            }
            return secondlargest;
        }
    };