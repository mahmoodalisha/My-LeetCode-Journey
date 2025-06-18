class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left<=right){
            int mid = left+(right-left)/2;

            if(nums[mid] == target){
                return true;
            }
            // When we can't tell which part is sorted because of duplicates
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                left++;
                right--;
            }
            else if(nums[left]<=nums[mid]){  //this portion is checking in the left half if left to mid is sorted
                if(nums[left]<=target && target < nums[mid]) //then it checks whether target lies inside the sorted range
                right = mid-1; //eliminating the right portion because we dont need to search in it
                else{
                    left = mid+1;
                }
            }
            //now check if the right portion is sorted
            else{
                if(nums[mid]<target && target <= nums[right]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }
        return false;
    }
};