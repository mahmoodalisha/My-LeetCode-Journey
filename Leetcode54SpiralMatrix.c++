
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result; // Vector to store the spiral order
        if (matrix.empty()) return result; // Return empty if the matrix is empty
        
        int top = 0, bottom = matrix.size() - 1; // Row boundaries
        int left = 0, right = matrix[0].size() - 1; // Column boundaries
        
        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int j = left; j <= right; j++) {
                result.push_back(matrix[top][j]);
            }
            top++; // Move down the top boundary
            
            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--; // Move left the right boundary
            
            // Ensure we are still in bounds before traversing
            if (top <= bottom) {
                // Traverse from right to left
                for (int j = right; j >= left; j--) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--; // Move up the bottom boundary
            }
            
            // Ensure we are still in bounds before traversing
            if (left <= right) {
                // Traverse from bottom to top
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Move right the left boundary
            }
        }
        
        return result; // Return the spiral order
    }
};
