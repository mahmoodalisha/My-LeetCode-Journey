class Solution {
public:
    vector<vector<int>>dp;
    const int MOD = 1e9 + 7;
    int getans(int m, int n, int row, int col, int currentstate,int prevstate){
        if (col == n){  //means you have reached the last column
            return 1;
        }
        if(row == m){ //when tou have reached the last row, you need to go to the next column
            return getans(m,n,0,col+1,0,currentstate);
        }
        if(row == 0 && dp[col][prevstate]!=-1){
            return dp[col][prevstate];
        }
        int up = 0; //hum jis row ko color karre hai hai uske upar wala row
        if(row>0){
            up = currentstate & 3;
        }
        int left = (prevstate >> ((m - row - 1) * 2)) & 3; //now update the state

        int ways = 0;

        for (int color = 1; color<=3; color++){
            if(color!=up && color != left){
                ways = (ways+getans(m,n,row+1,col,(currentstate<<2)+color,prevstate))%MOD;
            }
        }
        dp[col][prevstate] = ways;
        return ways;
        }

    int colorTheGrid(int m, int n) {
        dp = vector<vector<int>>(1000, vector<int>(1023,-1)); //table has 1000 rows (columns of the grid), and each row has 1023 columns
        return getans(m, n, 0, 0, 0, 0); //m,n,currentrow,currentcol,currentstate,prevstate

    }
};