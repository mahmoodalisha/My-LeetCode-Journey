class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int currentStreak = 1;
        int longestStreak = 1;

        for(int i = 1; i<nums.size();i++){
            if (nums[i]==nums[i-1]){  //This condition checks if the current number nums[i] is the same as the previous number nums[i - 1].
                continue; //skip the duplicate
            }
            else if(nums[i]==nums[i-1]+1){  //checks if the current number (nums[i]) is exactly one more than the previous number (nums[i - 1]).
                //increment the streak if it is consecutive
                currentStreak++;
            }
            else{
                longestStreak = max(longestStreak, currentStreak);
                currentStreak = 1;
            }
        }
        // Final check to update the longest streak
    longestStreak = max(longestStreak, currentStreak);

    return longestStreak;
    }
};