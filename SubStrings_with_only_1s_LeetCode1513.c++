/*
Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.

Example 1:
Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.
*/


//Pehle consecutive ones ka streak nikal lo, phir uspe formula laga do


class Solution {
public:
const int MOD = 1e9+7;
    int numSub(string s) {
        long long result = 0;
        long long count = 0;

        for(char c : s){
            if(c == '1'){
                count++;
            }
            else {
                result = (result+(count*(count+1)/2)%MOD)%MOD; //this is the real formula cum trick
                count = 0;
            }
        }
        //add the last streak if the streak ends with one
        result = (result+(count*(count+1)/2)%MOD)%MOD;
        return result;
    }
};
