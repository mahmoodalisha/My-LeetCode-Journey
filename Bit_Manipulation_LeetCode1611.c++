/*
1611. Minimum One Bit Operations to Make Integers Zero

Given an integer n, you must transform it into 0 using the following operations any number of times:

Change the rightmost (0th) bit in the binary representation of n.
Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.
Return the minimum number of operations to transform n into 0.

 

Example 1:

Input: n = 3
Output: 2
Explanation: The binary representation of 3 is "11".
"11" -> "01" with the 2nd operation since the 0th bit is 1.
"01" -> "00" with the 1st operation.


Example 2:
Input: n = 6
Output: 4
Explanation: The binary representation of 6 is "110".
"110" -> "010" with the 2nd operation since the 1st bit is 1 and 0th through 0th bits are 0.
"010" -> "011" with the 1st operation.
"011" -> "001" with the 2nd operation since the 0th bit is 1.
"001" -> "000" with the 1st operation.

*/

class Solution {
public:
    int minimumOneBitOperations(int n) {
         if(n == 0) return 0;
         vector<long long> F(32, 0);
         //create the F array
         //F[i] = no.of operations to convert a no. having only ith bit set to 0
         F[0] = 1; //matlab 0th bit set hai
         for(int i = 1; i<=30; i++){
            F[i] = 2*F[i-1]+1;
         }
         int result = 0;
         int sign = 1; //agar plus hoga toh plus karenge, minus hoga toh minus karenge

         for(int i = 30; i>=0; i--){ //left to right
            int ith_bit = ((1<<i) & n); //ith bit nikaalne ka tareeka
            if(ith_bit == 0){ //ith bit set hai ki nahi, ith bit set nahi hai toh aage badh jaao
                continue;
            }
            if(sign > 0){ //matlab positive hai
                result += F[i];   //"01001" = F[3] - F[0]
            }
            else{
                result -= F[i];
            }
            sign = sign*(-1);
         }
            return result;
    }
};
/*formula lagega 2*f(i-1)+1
f(i-1) jis ith bit pe khade hai wo set bit hai
f(4) = 2*f(3)+1
f(3) = 2*f(2)+1
*/