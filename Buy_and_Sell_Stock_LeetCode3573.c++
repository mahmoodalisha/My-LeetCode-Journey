//buy and sell stock V
//Dynamic Programming using Recursion + Memoization (Top-Down DP) with 3 cases

class Solution {
    long long t[1001][501][3]; //according to the constraints given
    //CASE 0 : you will buy-sell stock
    //CASE 1 : normal transaction : you have bought the stock, now sell it
    //CASE 2 : short sell
    long long solve(int i, int k, int CASE, vector<int> &prices){
        
        if(i == prices.size()){ //base case when i reaches the end
            if(CASE == 0)
                return 0;
                return INT_MIN;
        }
        
        if(t[i][k][CASE] != INT_MIN)
            return t[i][k][CASE];
        

        long long take = INT_MIN;
        long long skip;

        skip = solve(i+1, k, CASE, prices);

        //now the take action under which comes those three cases
        if(k>0){
            if(CASE == 1){ //normal transaction, bech do
                take = prices[i] + solve(i+1, k-1, 0, prices); //ek transaction bhi complete ho gai aur bechne se prices[i] mil raha hai
            }
            else if(CASE == 2){ //short sell karo
                take = -prices[i] + solve(i+1, k-1, 0, prices); 
            }
            else { // (CASE == 0)yahi pehla step hai jisme buy ya sell karre hai
                take = max(
                -prices[i] + solve(i+1, k, 1, prices), //buy karo
                 prices[i] + solve(i+1, k, 2, prices)); //short sell karo
            }
        }
        return t[i][k][CASE] = max(take, skip);
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        for(int i = 0; i<n; i++)
            for(int j = 0; j <= k; j++)
                for(int l = 0; l<3; l++)
                    t[i][j][l] = INT_MIN;
                
        return solve(0, k, 0, prices);
    }
};