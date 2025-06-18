//1493. Longest Subarray of 1's After Deleting One Element

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int current = 0;
        int prev = 0;
        int ans = 0;
        bool zerofound = false;

        for (int i : nums){
            if(i == 1){
                current++;
            }
            else{
                zerofound = true;
                ans = std::max(ans, current + prev);
                prev = current;
                current = 0;
                }
        }
        ans = std::max(ans, current + prev);
        // If no zero is found, we must remove one element, so the answer should be nums.size() - 1
        return zerofound ? ans : (nums.size() - 1);
    }
};

//current is to keep track of 1s before we encounter any 0
//prev is to update and make it previous after we enounter a 0
//so we just add prev and current and get the answer