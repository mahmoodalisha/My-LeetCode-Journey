/* return a binary string of length n that does not appear in nums

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.

asked by meta amazon google
*/
/*
Step1. Generate all strings of length n with the help of recursion and backtracking
Step2. usko return kardo jo binary string me nhi hai

You will need A set to store all strings in nums (for O(1) lookup).
*/

//curr means current binary string being built during recursion, So curr keeps growing until its length becomes n
//ans stores the binary string that is NOT present in nums
//If curr does not exist in the set Then we store it as the 

class Solution {
public:
    string ans = "";
    void solve(string curr, int n, unordered_set<string>& myset){
        if(curr.length() == n){
            if(myset.find(curr) == myset.end()){
                ans = curr;
            }
            return;
        }
        solve(curr + "0", n, myset);
        solve(curr + "1", n, myset);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> myset(nums.begin(), nums.end());

        solve("", n, myset);
        return ans;
    }
};