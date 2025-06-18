/*
DRY RUN
1. (int)log10(x) + 1
→ This gives the number of digits in x.

For example:
If x = 7896, then log10(7896) ≈ 3.8, so int(3.8) + 1 = 4 digits.
*/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int x : nums){
            int digits = (int)log10(x)+1;
            if(digits%2 == 0)
            count++;
        }
        return count;
    }
};