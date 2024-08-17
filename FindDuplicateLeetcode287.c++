Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3


//nothing but binary search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size()- 1;

        while(left<right){
            int mid = (left+right)/2;
            int count = 0;
        

        for (int num : nums){
            if (num <= mid){
                count++;
            }
        }
            if (count > mid) {
                right = mid;
                }
                else{
                    left = mid + 1;
                }
        }
            return left;
        }
    };
