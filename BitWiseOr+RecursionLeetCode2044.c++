class Solution {
public:

    int countsubsets(int idx, int currOr, vector<int>& nums, int maxOr){
        if(idx == nums.size()){
            if(currOr == maxOr){
                return 1; //found 1 subset
        }
        return 0;
    }
        int take = countsubsets(idx+1, currOr | nums[idx], nums, maxOr);
        int nottake = countsubsets(idx+1, currOr, nums, maxOr);

        return take+nottake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for (int &num : nums){
            maxOr |= num; //find the OR of all the elements
        }
        int currOr = 0;
        return countsubsets(0, currOr, nums, maxOr);
    }
};