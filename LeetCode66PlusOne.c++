/* Increment the large integer by one and return the resulting array of digits.
Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].*/


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n-1; i>=0; --i){  //starting from the rightmost
            if(digits[i]<9){
                digits[i]++;  //this adds 1 to the right most
                return digits;
            }
            digits[i]=0;  // If it's 9, set it to 0 and continue the carry

        }
        digits.insert(digits.begin(), 1); // If we exit the loop, it means all digits were 9, so add a 1 at the beginning
        return digits;
    }
};