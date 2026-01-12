/* DP + Monotonic Stack

Given a rows x cols binary matrix filled with 0's and 1's
find the largest rectangle containing only 1's and return its area.

Area = length x breadth, aur largest rectangle return karo jisme sirf 1 hai

The standard idea is:
1. Convert each row of the matrix into a histogram
2. For each histogram, compute Maximum Area Histogram (MAH)
*/

class Solution {
public:
    //Maximum Area Histogram
    int MAH(vector<int>& heights, int& n) {
        stack<int> st;
        int i = 0;
        int maxArea = 0;
        int area = 0;
        while(i < n) {
            if(st.empty() || heights[i] >= heights[st.top()]) {
                st.push(i++);
            } else {
                int index = st.top();
                st.pop();
                
                if(st.empty()) {
                    area = heights[index] * i;
                } else {
                    area = heights[index] * (i - st.top() - 1);
                }
                
                maxArea = max(maxArea, area);
            }
        }
        
        while(!st.empty()) {
            int index = st.top();
            st.pop();

            if(st.empty()) {
                area = heights[index] * i;
            } else {
                area = heights[index] * (i - st.top() - 1);
            }

            maxArea = max(maxArea, area);
        }
        
        return maxArea;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        
        int maxArea = 0;
        int m       = matrix.size();
        int n       = matrix[0].size();
        
        /*
        [1, 0, 1, 0, 0]
        [1, 0, 1, 1, 1] =>  [2, 0, 2, 1, 1]
        [1, 1, 1, 1, 1] =>  [3, 1, 3, 2, 2]
        [1, 0, 0, 1, 0] ->  [3, 0, 0, 3, 0]
        */
        
        vector<int> heights(n, 0);
        for(int col = 0; col < n; col++) {
            heights[col] = matrix[0][col] == '0' ? 0 : 1;
        }
        
        maxArea = MAH(heights, n);
        
        for(int row = 1; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(matrix[row][col] == '0') {
                    heights[col] = 0;
                } else {
                    heights[col] += 1;
                }
            }
            
            maxArea = max(maxArea, MAH(heights, n));
        }
        
        return maxArea;
    }
};
//youtube : code story with MIK