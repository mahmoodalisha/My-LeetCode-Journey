class Solution {
public:
    int func(vector<int>& v, int i, int j, vector<vector<int>>& dp){
        if(j-i<=1) return 0; //this means no triangle can be formed
        if(j-i == 2) return v[i]*v[i+1]*v[j]; //possible to form only one triangle
        if(dp[i][j]!=-1) return dp[i][j]; //do not repeat calculated subproblem this is memoization 
        // Jab recursion chalti hai, ek hi (i, j) range ke liye calculation bar-bar ho sakta hai. 
        // Agar humne us range ka answer pehle hi calculate karke dp[i][j] me store kar liya hai, 
        // toh dubara recursion chalane ki zaroorat nahi hai. Hum bas direct wahi stored answer return kar dete hain.
        int res = INT_MAX;
        for(int k =i+1; k<j; k++){
        res = min(res, func(v,i,k, dp)+v[i]*v[k]*v[j]+func(v,k,j, dp));
        }
        dp[i][j] = res; //caching memoising
        return res;
    }


    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); //ek 2D dp array initialize kar do aur -1 se initialize karo
        return func(values, 0 , n-1, dp);
    }
};
//polyscore = leftPolyscore + a0a2a5 + rightPolyscore
//DRY RUN in my algo copy