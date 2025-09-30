class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i = 0; i<numRows; i++){
           result[i] = vector<int>(i+1,1); //har row pe jo vector hone wala hai uska size hai aur uska size i+1 hai
           for(int j = 1; j<i; j++){
            result[i][j] = result[i-1][j] + result[i-1][j-1];
           }
        }
        return result;
    }
};
//i matlab row
//i-1 just upar wala row
//j matlab column
//j-1 just upar wala column