//DP Approach with LIS Technique
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int col = strs[0].size();

        vector<int> dp(col, 1);
        int LIS = 1;

        //traditional LIS pattern
        for(int i = 0; i<col; i++){
            for(int j = 0; j<i; j++){
                bool valid = true;
                for(int k = 0; k<row; k++){
                    if(strs[k][j] > strs[k][i]){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            LIS = max(LIS, dp[i]);
        }
        return col - LIS;
    }
};
//youtube : code story with MIK