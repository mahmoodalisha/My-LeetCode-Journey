/*
You are given a binary string s.
You can perform the following operation on the string any number of times:

Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
Move the character s[i] to the right until it reaches the end of the string or another '1'. For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".
Return the maximum number of operations that you can perform.


Example 1:
Input: s = "1001101"
Output: 4

Explanation:

We can perform the following operations:

Choose index i = 0. The resulting string is s = "0011101".
Choose index i = 4. The resulting string is s = "0011011".
Choose index i = 3. The resulting string is s = "0010111".
Choose index i = 2. The resulting string is s = "0001111".
Example 2:

*/

//zero se pehle saare ones ko count kar lo
class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int operations = 0;
        int countOnes = 0;
        int i = 0;

        while(i<n){
            if(s[i] == '0'){
                operations += countOnes;
                while(i<n && s[i] == '0') //move till first 1 occurs
                    i++;
            }
            else {
                countOnes++;
                i++;
            }
        }
        return operations;
    }
};