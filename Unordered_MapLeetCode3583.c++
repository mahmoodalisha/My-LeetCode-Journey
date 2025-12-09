class Solution {
public:
    int MOD = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, long long> left, right;
        // Step 1: Build RIGHT frequency
        for(int c : nums){
            right[c]++;
        }
        long long ans = 0;
        // Step 2: Fix each j as middle
        for(int j = 0; j<nums.size(); j++){
            int mid = nums[j];
            // Remove current j from right
            right[mid]--;
            int need = nums[j]*2;

            if(left.count(need) && right.count(need)){
                ans = (ans + left[need]*right[need])%MOD;
            }
            // Add current j to left
            left[mid]++;
        }
        return ans;
    }
};