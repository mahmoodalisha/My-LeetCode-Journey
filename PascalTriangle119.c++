class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev; //for the previous row
        for(int i = 0; i<rowIndex+1; i++){
            vector<int> curr(i+1, 1);
        
        for(int j = 1; j<i; j++){
            curr[j] = prev[j] + prev[j-1];//har row ke liye current vector banega previous vector ko dekh dekh ke
        }
        prev = curr; //update ho jayega
     }
        return prev;
    }
};
//youtube: code story with mik