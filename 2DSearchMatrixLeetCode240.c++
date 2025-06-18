/*
| Approach                     | Time Complexity    | Works well when           | Best for Leetcode 240 |
| ---------------------------- | ----------------   | ------------------------- | --------------------- |
| Staircase Search (Top-Right) | ✅ O(m + n)       | Always optimal            | ✅ YES                 |
| Binary Search per Row        | O(m * log n)       | m small, n large          | ❌ Slower              |
| Binary Search per Column     | O(n * log m)       | n small, m large          | ❌ Slower              |
| Full 2D Binary Search        | ❌ Not applicable  | Needs fully sorted matrix | ❌ Not applicable      |

*/

//we are not moving in both directions(both rows and column) together
//what are x and y?
//x → Row index (starting from 0)
//y → Column index (starting from n - 1, i.e., the last column)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = n-1;
        
        while (x < m && y >= 0) {
            if(matrix[x][y] == target){
                return true;
            }
            else if(matrix[x][y]>target){
                y--; //target se bada hai to left jaao
            }
            else x++; //nahi to down jaao
        }
        return false;
    }
};

/*
while (x < m && y >= 0)
Now, line-by-line meaning:
x < m
You're going downward in the matrix.
This ensures that you don't go beyond the bottom of the matrix.
Since valid row indices are 0 to m - 1, x must be less than m.

y >= 0
You're going leftward in the matrix.
This ensures that you don't go before the first column.
Since valid column indices are 0 to n - 1, y must be greater than or equal to 0.

⛔ If either condition fails:
If x == m, you've gone past the last row → out of bounds.
If y == -1, you've gone before the first column → out of bounds.
*/