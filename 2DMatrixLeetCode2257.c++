class Solution {
    void markguarded(int row, int col, vector<vector<int>>& grid){
        //UP
        for(int i = row-1; i>=0; i--){
            if(grid[i][col] == 2 || grid[i][col] == 3){
            break;
        }
        grid[i][col] = 1; //marking it as guarded
      }
      //Down
      for(int i = row+1; i<grid.size(); i++){ //down jaane me row change hoga column constant rahega
            if(grid[i][col] == 2 || grid[i][col] == 3){
            break;
        }
        grid[i][col] = 1; //marking it as guarded
      }
      //left
      for(int j = col-1; j>=0; j--){
            if(grid[row][j] == 2 || grid[row][j] == 3){
            break;
        }
        grid[row][j] = 1; //marking it as guarded
      }
      //right
      for(int j = col+1; j<grid[0].size(); j++){
            if(grid[row][j] == 2 || grid[row][j] == 3){
            break;
        }
        grid[row][j] = 1; //marking it as guarded
      }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n,0));

        //step 1. mark guard positions
        for(auto &g : guards){
            int i = g[0];
            int j = g[1];
            grid[i][j] = 2; //guard yaha baitha hua hai isko grid me mark kardo, kuch bhi 2,3,4,5 koi bhi no. daalke mark kardo
        }
        //step 2. mark wall positions
        for(auto &w : walls){
            int i = w[0];
            int j = w[1];
            grid[i][j] = 3; //yaha pe wall hai mark kardo
        }
        //step 3. four directions me check karo and mark karo guarded
        for(auto &guard : guards){
            int i = guard[0];
            int j = guard[1];
            markguarded(i, j, grid);
        }
        //step 4. count karlo poore grid me
        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    count++; //matlab ye unguarded hai
                }
            }
        }
        return count;
    }
};
//youtube : code story with MIK