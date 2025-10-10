//bottom up approach+Greedy
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        int maxEnergy = INT_MIN;
        for(int i = n-1; i>=0; i--){
            if(i+k<n)
            dp[i] = energy[i]+dp[i+k];
            else
            dp[i] = energy[i];

            maxEnergy = max(maxEnergy, dp[i]);
        }
        return maxEnergy;
    }
};
/* 
Step 3: Formula ka matlab dp[i] = energy[i] + dp[i + k]
Agar main index i pe hoon, to mujhe abhi energy[i] milegi,
aur phir agar aage ja sakti hoon (i+k < n), to us jagah se milne wali best energy dp[i+k] bhi jod do


energy = [5, 2, -10, -5, 1]
k = 3
i = 4 → dp[4] = 1
i = 3 → dp[3] = -5
i = 2 → dp[2] = -10
i = 1 → dp[1] = 2 + dp[4] = 3
i = 0 → dp[0] = 5 + dp[3] = 0
So dp = [0, 3, -10, -5, 1]
Answer = max(dp) = 3
*/