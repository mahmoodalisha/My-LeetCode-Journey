class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.length()-1; i>=0; i--){
            if((num[i]%2) != 0){
                return num.substr(0,i+1);  //from 0 to that position add the substring
            }
        }
        return "";
    }
};