class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0;
        int current_jump = 0;
        int count = 0;

        for(int i = 0; i<nums.size()-1; i++){
            maxReach = max(maxReach, i+nums[i]);
            if(i == current_jump){
                count++;
                current_jump = maxReach;
            }
        }
        return count;
    }
};