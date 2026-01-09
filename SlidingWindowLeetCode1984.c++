//sliding window
//left matlab i
//right matlab i+k-1
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int best = INT_MAX;
        for(int i = 0; i+k-1<nums.size(); i++){
            int diff = nums[i+k-1] - nums[i];
            best = min(best, diff);
        }
        return best;
    }
};
/* window ka size = k = 3 hai
🔹 i = 0
[ 1 , 4 , 7 , 9 , 12 ]
  ↑       ↑
 nums[i]  nums[i+k-1]

nums[i] = 1
nums[i + k - 1] = nums[2] = 7

👉 diff = 7 - 1 = 6
 */