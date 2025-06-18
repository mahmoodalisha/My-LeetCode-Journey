class Solution {
public:
    int m;
    int n;
    int perimeter = 0;
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0) { //out of bound ho gaya toh matlb baahar nikal gaye ho island se
        perimeter++; //perimeter nikal lo
        return; //phir return ho jaao
        }
        if(grid[i][j] == -1){ //kahi island visited to nahi hai
            return;
        }
        grid[i][j] =-1; //agar island me hi hai mark visited
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};

//youtube: code story with MIK