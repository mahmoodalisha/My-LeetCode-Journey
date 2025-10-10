//using DFS and also applying binary search
class Solution {
public:
    int n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool ispossibleToReach(vector<vector<int>> &grid, int i, int j, int t, vector<vector<bool>>& visited){
        if(i<0 || i>=n || j< 0 || j>= n || visited[i][j] == true || grid[i][j]>t){
            return false;
        }
        
        visited[i][j] = true;

        if(i == n-1 && j == n-1){ //matlab pahunch gaye
            return true;
        }

        for(auto &dir : directions){
            int i_ = i+dir[0]; //neighbour
            int j_ = j+dir[1]; //neighbour

            if(ispossibleToReach(grid, i_, j_, t, visited)){
                return true;
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) { //binary search
        n = grid.size();
        int l = grid[0][0]; //grid 0,0 pe start karre ho, also the left pointer
        int r = n*n-1;
        int result = 0;

        while(l<=r){
            int mid = (l+r)/2;
            
            vector<vector<bool>> visited(n, vector<bool>(n, false)); //visited mark karne ke liye ek vector lelo
            if(ispossibleToReach(grid, 0, 0, mid, visited)){
            result = mid;
            r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
};

//ek unit time ke liye ek unit level paani bharega aur elevation doobega tab hi hum swim kar payenge
//mujhe [m-1][n-1] tak jana hai matlab last cell tak toh isiliye DFS laga do