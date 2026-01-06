/*
Given an array of integers arr, return the number of subarrays with an odd sum.
Since the answer can be very large, return it modulo 109 + 7.

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
*/

//Approach :- Prefix Sum with Frequency Counting

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9+7;

        int evenCount = 1; //prefix sum = 0;
        int oddCount  = 0;
        int sum       = 0;
        long long ans = 0;

        for(int x : arr){
            sum += x;
            if(sum % 2 == 0){
                ans = (ans + oddCount) % MOD;
                evenCount++;
            } else{
                ans = (ans + evenCount) % MOD;
                oddCount++;
            }
        }
        return ans;
    }
};