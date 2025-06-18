//same as that of leetcode 463 same 2 same

class Solution {
public:
    int m;
    int n;
    int island = 0;
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!='1'){
            return;
        }
        
        grid[i][j] = 'v'; //mark as visited
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1') {//island mil gaya
                dfs(grid, i, j); //matlab uska jo jo vertical horizntal neighbour hai jo jo 1 hai, uspe DFS laga do
                island++;
            }
        }
    }
        return island;
    }
};
//youtube: code story with mik