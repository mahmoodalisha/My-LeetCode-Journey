//Best Time to buy and sell stocks Leetcode question 121

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = prices[0];
        int totalprofit = 0;
        for(int i = 0; i<prices.size(); i++){
            totalprofit = max(totalprofit, prices[i]-minprice);
            minprice = min(minprice, prices[i]);
        }
        return totalprofit;
    }
};