//153. Find Minimum in Rotated Sorted Array
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
      

        while(left<right){
            int mid = (left + right)/2;
            // If middle element is greater than the rightmost element,
            // the minimum is in the right half
            if(nums[mid]>nums[right]){
                left = mid+1;
            }
            // Otherwise, the minimum is in the left half (including mid)
            else{
                right=mid;
            }
        }
        // After the loop ends, left will point to the minimum element
        return nums[left];
    }
};