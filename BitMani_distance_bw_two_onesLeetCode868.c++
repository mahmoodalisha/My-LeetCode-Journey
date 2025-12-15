/*
Example 1:

Input: n = 22
Output: 2
Explanation: 22 in binary is "10110".
The first adjacent pair of 1's is "10110" with a distance of 2.
The second adjacent pair of 1's is "10110" with a distance of 1.
The answer is the largest of these two distances, which is 2.
Note that "10110" is not a valid pair since there is a 1 separating the two 1's underlined.
*/

class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int ans = 0;
        int curr = 0;

        while(n>0){
            if(n & 1){  //check if last bit is 1
                if(last != -1){
                    ans = max(ans, curr-last);
                }
                last = curr;
            }
            curr++;
            n >>= 1; //shift right
        }
        return ans;
    }
};

/*
n & 1 → checks the current binary bit

curr → current bit position

last → position of previous 1

Distance = pos - last

n >>= 1 → move to the next bit


*/