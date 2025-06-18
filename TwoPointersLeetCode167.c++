//this is only two pointer approach and not sliding window
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left<right){
            int sum = numbers[left]+numbers[right];
            if(sum == target){
                return {left+1, right+1};
            }
            else if (sum<target){
                left++;
            }
            else
                right--;        
        }
        return {};
    }
};