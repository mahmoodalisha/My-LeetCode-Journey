//third approach : bottom up LIS Variant
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n,1); //for mod == 1
        vector<int> dp0(n,1); //for mod == 0
        int maxSubsequenceLength = 1;

        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                int mod = (nums[i]+nums[j])%2;

                if(mod == 1){
                    dp1[i] = max(dp1[i], 1+dp1[j]);
                    maxSubsequenceLength = max(maxSubsequenceLength, dp1[i]);
                }
                else{ //mod == 0 ke liye
                    dp0[i] = max(dp0[i], 1+dp0[j]);
                    maxSubsequenceLength = max(maxSubsequenceLength, dp0[i]);
                }
            }
        }
        return maxSubsequenceLength;
    }
};
//youtube: code story with mik