//formula is:
// 
//original_total_profit + (modified_window_profit - original_window_profit)
class Solution {
public:
typedef long long ll;
    ll maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        ll original_profit = 0;
        vector<ll> profit(n); //original profit each day
        for(int i = 0; i<n; i++){
            profit[i] = (ll)prices[i]*strategy[i];
            original_profit += profit[i];
        }

        ll original_window_profit = 0;
        ll modified_window_profit = 0;
        ll max_gain = 0; //modified_window_profit - original_window_profit

        int i = 0;
        int j = 0;

        while(j<n){
            original_window_profit += profit[j];

            //second half of the window contributes to modifiedWindowProfit 
            if(j-i+1 > k/2){
                modified_window_profit += prices[j];
            }
            if(j-i+1 > k){
                original_window_profit -= profit[i];
                modified_window_profit -= prices[i + k/2];
                i++;
            }
            if(j-i+1 == k){
                max_gain = max(max_gain, modified_window_profit - original_window_profit);
            }
            j++;
        }
        return original_profit + max_gain;
    }
}; 

//youtube : code story with MIK