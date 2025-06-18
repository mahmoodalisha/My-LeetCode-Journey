class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxans = 0;
        for(int i = 0; i<n; i++){
            maxans = max(maxans, abs(nums[i]-nums[(i+1)%n]));
        }
        return maxans;
    }
};