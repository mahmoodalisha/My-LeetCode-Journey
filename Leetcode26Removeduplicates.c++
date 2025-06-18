//Leetcode 26
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            //for optimal soln we'll use two pointer approach
            int i = 0;
            for(int j = 1; j< nums.size(); j++){
                if(nums[i] != nums[j]){
                    i++; //move the poiter
                    nums[i] = nums[j]; //updating the pointer assign the poniter
                }
            }
            return i+1;
        }
    };