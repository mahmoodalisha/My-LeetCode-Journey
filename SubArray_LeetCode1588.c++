/*
Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.

A subarray is a contiguous subsequence of the array.

Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
*/

//Each element contributes to several odd-length subarrays. I count how many such subarrays include it and add its contribution

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        for(int i = 0; i<n; i++){
            int left = i+1;
            int right = n-i;
            int total = left*right;
            int odd = (total+1)/2;

            ans += arr[i]*odd;
        }
        return ans;
    }
};

/*
What are left and right?
We are standing on one element arr[i] and asking:
In how many subarrays does this element appear?
To form a subarray containing arr[i]:
we choose a start index on the left
we choose an end index on the right

left = i + 1
This counts how many ways we can choose the start of the subarray.

Why?
Indices go from 0 to i. Example :
arr = [1, 4, 2, 5, 3]
indexes: 0  1  2  3  4
               ↑
               i = 2
Possible starts:
0, 1, 2   → 3 choices

So:
left = i + 1 = 3
*/