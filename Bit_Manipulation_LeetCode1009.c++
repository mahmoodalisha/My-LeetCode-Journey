/* given input n = 5
step1: convert to binary = 101
step2: flip   = 010
step3: answer = 2
*/

/* XOR gives 1 when bits are different
| A | B | A ^ B |
| - | - | ----- |
| 0 | 0 | 0     |
| 0 | 1 | 1     |
| 1 | 0 | 1     |
| 1 | 1 | 0     |
*/

/*
We create a mask of the same length.
n    = 101
mask = 111
Then:
101
^111
----
010

Result = 2
*/
//  << is the bitwise left shift operator, It moves all bits to the left. | is the bitwise OR operator.

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int mask = 0;
        int temp = n; //copy of n in temp

        while(temp > 0){
            mask = (mask << 1) | 1; //| 1 ensures the last bit becomes 1
            //1️⃣ shift mask left
            //2️⃣ put 1 at the end
            temp >>= 1; 
        }
        return mask ^ n;
    }
};