/*
grid = [[1,2,3],
        [4,5,6],
        [7,8,9]]
k = 1

Flatten → [1,2,3,4,5,6,7,8,9]
Shifted → [9,1,2,3,4,5,6,7,8]

Rebuild →
[[9,1,2],
 [3,4,5],
 [6,7,8]]

Complexity
Time: O(m × n)
Space: O(m × n)
Instead of looping k times and shifting the whole grid each time,
(i + k) % total directly computes where each element will land after k shifts.

How are we computing k iterations :
Step 1️⃣: Example 2 of the input array: Flatten the grid into a 1D array
flat = [3,8,1,9,19,7,2,5,4,6,11,10,12,0,21,13]
Length = total = 16

Step 2️⃣: Compute new index for each element
We’re doing
shifted[(i + k) % total] = flat[i]
| i   | flat[i] | (i + k) % total | new position in shifted |
| --- | ------- | --------------- | ----------------------- |
| 0   | 3       | (0+4)%16 = 4    | shifted[4] = 3          |
| 1   | 8       | (1+4)%16 = 5    | shifted[5] = 8          |
| 2   | 1       | (2+4)%16 = 6    | shifted[6] = 1          |
| 3   | 9       | (3+4)%16 = 7    | shifted[7] = 9          |
| 4   | 19      | (4+4)%16 = 8    | shifted[8] = 19         |
| ... | ...     | ...             | ...                     |
| 12  | 12      | (12+4)%16 = 0   | shifted[0] = 12         |
| 13  | 0       | (13+4)%16 = 1   | shifted[1] = 0          |
| 14  | 21      | (14+4)%16 = 2   | shifted[2] = 21         |
| 15  | 13      | (15+4)%16 = 3   | shifted[3] = 13         |

*/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m*n;
        //step 1 : flatten the grid into array
        vector<int> flat;
        for(auto &row : grid){
            for(int val : row){
                flat.push_back(val);
            }
        }
        k = k%total;
        //step 2 : compute k
        vector<int> shifted(total);
        for(int i = 0; i<total; i++){
            shifted[(i+k)%total] = flat[i];
        }
        //step 3 : now build the matrix
        vector<vector<int>> result(m, vector<int>(n));
        int index = 0; 
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                result[i][j] = shifted[index++];
            }
        }
        return result;
    }
};