/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
*/

class Solution {
public:
    bool isMagicGrid(vector<vector<int>>& grid, int row, int col){
        //1 to 9 hona chahiye and distinct numbers hona chahiye
        unordered_set<int> myset;

        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                int num = grid[row+i][col+j];
                if(num<1 || num>9 || myset.count(num)){
                    return false;
                }
                else{
                    myset.insert(num);
                }
            }
        }
        //sum banao aur dekhoo
        int SUM = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        for(int i = 0; i<3; i++){
            //Row ka sum check karo
            if(grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2] != SUM){
             return false;   
            }
            //ye column ka sum check karo
            if(grid[row][col+i] + grid[row+1][col+i] + grid[row+2][col+i] != SUM){
             return false;   
            }
        }
        //diagonal
        if(grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != SUM) return false;
        //anti diagonal
        if(grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != SUM) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count_magic_grid = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i<=rows-3; i++){
            for(int j = 0; j<=cols-3; j++){
                if(isMagicGrid(grid, i, j)){
                    count_magic_grid++;
                }
            }
        }
        return count_magic_grid;
    }
};

//youtube : code story with MIK