class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int s = 0;
        int m = INT_MAX;
        
        for(int r = 0; r < n; r++){
            s += nums[r];  // ✅ new element add karo

            while(s >= target){
                m = min(m, r - l + 1);  // ✅ window length
                s -= nums[l];          // ✅ remove leftmost
                l++;                   // ✅ move left ahead
            }
        }

        return (m == INT_MAX) return 0;
        else return m;
    }
};
