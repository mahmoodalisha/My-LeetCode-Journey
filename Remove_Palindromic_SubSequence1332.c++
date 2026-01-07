/* leetcode 1332
There are only 3 possible answers:
0 → if string is already empty
1 → if the entire string is a palindrome
2 → otherwise
 */

class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0;
        int j = s.size()-1;

        while(i<=j){
            if(s[i] != s[j]){
                return 2;
            }
            i++;
            j--;
        }
        return 1;
    }
};