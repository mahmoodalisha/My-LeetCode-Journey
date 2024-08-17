//Best Time to buy and sell stocks Leetcode question 121

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];  //prices[0] is the first index and indicates the stock buying day
        int profit = 0;

        for (int i = 1; i< prices.size(); i++){
            int diff = prices[i] - minimum ;
            profit = max(profit, diff);    //This line sets profit to the greater value between the current profit and diff.
            minimum = min(minimum, prices[i]);   //This line sets minimum to the smaller value between the current minimum and prices[i].
        }
        return profit;
    }
};