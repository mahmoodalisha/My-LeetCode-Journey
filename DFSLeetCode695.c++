//find the max area of the island
class Solution {
public:
    //four directions //i, j = current cell //m, n = total rows and columns
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>>& grid, int i, int j, int &m, int &n){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        int count = 1;
        grid[i][j] = 0; //Pehle maan lo current cell (i, j) part of island hai → count = 1 grid[i][j] = 0 kar diya → mark visited (taaki dobara is par na aaye)
        for(vector<int> &dir : directions){
            int newi = i+dir[0]; //next cell ke liye
            int newj = j+dir[1]; //next cell ke liye
            count += dfs(grid, newi, newj, m, n);
        }
        return count; //return the area
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, dfs(grid, i, j, m, n));
                }
            }
        }
        return maxArea;
    }
};