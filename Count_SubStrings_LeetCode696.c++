//Count Binary SunStrings
/*
Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.


Example 1:

Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
*/

/* All 0s and 1s are grouped consecutively
Valid examples: "01", "10", "0011", "1100"

Invalid: "0101"  ❌ (not grouped)

Dry run:-
s = "00110"
Groups:
00 (2), 11 (2), 0 (1)

Steps:
transition 00 → 11 → ans += min(2,2) = 2
transition 11 → 0 → ans += min(2,1) = 1

Final:
ans = 3
Each valid substring comes from two adjacent groups of 0s and 1s.
The number of such substrings is limited by the smaller group size.
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 1;
        int ans = 0;
        for(int i = 1; i<s.size(); i++){
            if(s[i] == s[i-1]){
                curr++;
            }
            else{
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }  
        ans += min(prev, curr);
        return ans;
    }
};