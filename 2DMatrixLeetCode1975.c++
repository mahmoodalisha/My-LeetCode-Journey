//apply operation any number of time by multiplying with -1
//Greedy Approach

//agar negative numbers odd times hai poore matrix me toh -1 se multiply krte karte sab positive ban jayega
//agar negative number even times hai toh sabse chhota number ko -1 se multiply karo

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size(); //n*n matrix hai toh yahi no. of rows hai yahi no. of columns

        long long sum = 0;
        int countNegatives = 0;
        int smallestAbsoluteValue = INT_MAX;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                sum += abs(matrix[i][j]);

                if(matrix[i][j]<0){ //matlab negative hai
                    countNegatives++;
                }
                smallestAbsoluteValue = min(smallestAbsoluteValue, abs(matrix[i][j]));
            }
        }
        if(countNegatives % 2 == 0){ //matlb matrix me even no. of negative hai
            return sum; //sabko positive bana payenge jo answer tha wahi return kardo
        }
        return sum-2*smallestAbsoluteValue;
    }
};