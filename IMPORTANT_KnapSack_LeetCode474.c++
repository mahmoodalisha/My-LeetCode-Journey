/*   Knapsack + Dynapmic Programming Approach
You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.

In LeetCode 474, you don’t have weights and values — but it’s still the same idea:

Knapsack analogy	LeetCode 474 meaning
Item	A binary string (like "10", "0001")
Weight	How many 0s and 1s that string uses
Bag capacity	You have at most m zeros and n ones
Value	1 (each string counts as one item)
Goal	Maximize number of strings you can include
💡 So your "bag" has two limits:

m zeros
n ones

This makes it a 2D Knapsack problem (because two constraints).

🧠 DP State meaning:
dp[i][j] = maximum number of strings you can form using at most i zeros and j ones
*/

/*
🧩 Example:
strs = ["10", "0", "1"]
m = 1  (you can use 1 zero)
n = 1  (you can use 1 one)

Now check all possible subsets of strings:
| Subset     | Total zeros | Total ones | Valid?           |
| ---------- | ----------- | ---------- | ---------------- |
| ["10"]     | 1           | 1          | ✅                |
| ["0"]      | 1           | 0          | ✅                |
| ["1"]      | 0           | 1          | ✅                |
| ["0","1"]  | 1           | 1          | ✅                |
| ["10","0"] | 2           | 1          | ❌ too many zeros |
| ["10","1"] | 1           | 2          | ❌ too many ones  |
✅ The largest valid subset is ["0", "1"] → 2 strings.

So answer = 2.
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //// dp[i][j] = max number of strings we can form with i zeros and j ones

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(string s : strs){
            //count zeroes and ones in the current string
            int zeros = 0;
            int ones  = 0;
            for(char c : s){
                if(c == '0') zeros++;
                else ones++;
            }
            // traverse backwards (to not overwrite values we still need)
            for(int i = m; i>=zeros; i--){
                for(int j = n; j>= ones; j--){
                    //either take this string or leave it
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};