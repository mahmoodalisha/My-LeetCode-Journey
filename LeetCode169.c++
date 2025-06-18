class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element;

        for(int i = 0;i<nums.size();i++){
            if(count == 0){    //when the count becomes 0 and resets
                count = 1;
                element = nums[i];    //now this is my current element
            }
            else if(nums[i] == element){
                count++;
            }
            else{
                count--;
            }
        }
        return element;
    }
};