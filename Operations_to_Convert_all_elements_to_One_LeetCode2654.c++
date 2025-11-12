/*
You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:

Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.

The gcd of two integers is the greatest common divisor of the two integers.
*/

//jo value aaya us ka next se GCD nikal lo
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 1) count1++;
        }
        if(count1 > 0){ //base case pahunch gaya
             return n - count1;
        }
        int operations = INT_MAX;
        for(int i = 0; i<n; i++){
            int GCD = nums[i];
            for(int j = i+1; j<n; j++){
                GCD = gcd(GCD, nums[j]);

                if(GCD == 1){
                    operations = min(operations, j-i);
                    break;
                }
            }
        }
        if(operations == INT_MAX){
            return -1;
        }
        return operations + (n-1);
    }
};

//youtube : code story with MIK