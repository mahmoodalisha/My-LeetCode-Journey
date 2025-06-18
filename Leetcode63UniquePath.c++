class Solution {
public:

        int dp[101][101];
        int solve(int i, int j, int m, int n){
    
        if(i < 0 || i >= m || j < 0 || j >= n) //check if out of boundaries
        return 0;

        if(i == m-1 && j == n-1)    
        return 1; //this means we have found one way to reach to the end

        if(dp[i][j] != -1)  //this is called memoizaton
        return dp[i][j];
        
        int right = solve(i, j+1, m, n);
        int down = solve(i+1, j, m, n);

        return dp[i][j] == right + down;

        }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m, n); //0,0 as the robot is standing at 0,0
        
    }
};