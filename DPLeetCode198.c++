class Solution {
public:

    int solve(vector<int>& nums, int i, int n){
        int t[101];
        if(i>=n){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }

        int steal = nums[i]+solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return t[i] = max(steal, skip)
    }
    int rob(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        int n = nums.size();
        return solve(nums, 0, n);
    }
};

//Take money from house i → nums[i]
//Skip the next house → move to house i + 2