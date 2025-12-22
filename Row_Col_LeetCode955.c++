/*
we are storing the information of previous row whether they are sorted or not with the help of this
bool array and marking along we go

      c0 c1 c2
row0   a  b  x
row1   a  c  y
row2   a  c  z
*/


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int col = strs[0].size();

        vector<bool> sorted(row - 1, false); 
        int del = 0;

        for (int c = 0; c < col; c++) {
            bool mark = false;
            for (int r = 0; r < row - 1; r++) {
                if (!sorted[r] && strs[r][c] > strs[r + 1][c]) {
                    del++;
                    mark = true;
                    break;
                }
            }

            if (mark) continue;

            // mark newly sorted pairs
            for (int r = 0; r < row - 1; r++) {
                if (strs[r][c] < strs[r + 1][c]) {
                    sorted[r] = true;
                }
            }
        }
        return del;
    }
};
//youtube : code story with MIK
//similar question : leetcode 944 (Easy)
//similar question : leetcode 960 (Hard)