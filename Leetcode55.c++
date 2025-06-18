class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0; // Track the maximum index we can reach
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // If the current index is beyond the maximum reachable index, return false
            if (i > maxReach) {
                return false;//If at any point, an index is found that is not reachable (i > maxReach), the function returns false.
            }
            // Update the maximum reachable index
            maxReach = std::max(maxReach, i + nums[i]);
        }

        // If we can get to or beyond the last index
        return true;
    }
};
