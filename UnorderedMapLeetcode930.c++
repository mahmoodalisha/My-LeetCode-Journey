class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        int count = 0;
        int presum = 0;

        for(int i = 0; i<n; i++){
            presum += nums[i];
            int remove = presum-goal;
            count += mpp[remove];
            mpp[presum] += 1;
        }
        return count;
    }
};
//560, 930, 1074 all belong to same category youtube: code story with MIK
//dry run in my DSA copy