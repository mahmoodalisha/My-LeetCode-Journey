/*
Given Matrix:
mat = [
  [1,0,0],
  [0,0,1],
  [1,0,0]
]

rowCount = [1,1,1]   number of 1s in each row
colCount = [2,0,1]   number of 1s in each column

Step 3: How we use these array

Check each 1:
(0,0) → rowCount[0]=1 ✅, colCount[0]=2 ❌ → NOT special
(1,2) → rowCount[1]=1 ✅, colCount[2]=1 ✅ → SPECIAL ✅
(2,0) → rowCount[2]=1 ✅, colCount[0]=2 ❌ → NOT special

So count = 1, which matches the expected answer.
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        int row = mat.size();
        int col = mat[0].size();
        vector<int> rowCount(row, 0);
        vector<int> colCount(col, 0);

        for(int r = 0; r<row; r++){
            for(int c = 0; c<col; c++){
                if(mat[r][c] == 1){
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};