//each array inside mat i.e mat[m] is a row
//
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       int m = mat.size(); //row
       int n = mat[0].size(); //column
       // If reshape not possible, return original matrix
        if (m * n != r * c) return mat;

        vector<vector<int>> result(r, vector<int> (c));
        int row = 0;
        int col = 0;

       
       for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            result[row][col] = mat[i][j];
            col++;
            if(col==c){ //move to next row
                col = 0;
                row++;
            }
            }
            }
       
       return result;
    }
};