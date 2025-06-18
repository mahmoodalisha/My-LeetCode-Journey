//greedy approach, this is for sure that our total gas will not exceed the total cost
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalkamai = accumulate(begin(gas), end(gas), 0);
        int totalkharcha = accumulate(begin(cost), end(cost), 0);

        if(totalkamai<totalkharcha){
            return -1;
        }

        int result = 0;
        int expenditure = 0;

        for(int i = 0; i<gas.size();i++){
             expenditure += gas[i]-cost[i];
        
        if(expenditure<0){
            result = i+1;  //ab next gas station se start karo
            expenditure = 0;
        }
    }
        return result;  //jaha se start kia uska index return kardo
    }
};