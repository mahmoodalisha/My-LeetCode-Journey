class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(char c : columnTitle){
            int value = c - 'A'+1;
            result = result*26+value;
        }
        return result;
    }
};
/*
formula : 
Input: "AB" = 1*26 + 2 = 28
Input: "ZY" = 26*26 + 25 = 701
*/