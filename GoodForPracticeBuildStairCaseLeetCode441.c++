//brute force approach first TC of this code is O(Sqrt(N))
class Solution {
public:
    int arrangeCoins(int n) {
        long long coins = n;
        int row = 1;

        while(coins >= row){
            coins -= row; // use 'row' coins to fill the current row
            row++; // move to next row
        }
        return row-1;
    }
};
/*
coins = 8
row = 1

Step 1:
Need row = 1 coin to build row 1
Do we have enough? ✅ yes (8 ≥ 1)
Build it → spend 1 coin
Update coins:
coins = coins - row = 8 - 1 = 7

*/

//now optimal TC is O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        long long k = (sqrt(1 + 8LL * n) - 1) / 2;
        return (int)k;
    }
};


