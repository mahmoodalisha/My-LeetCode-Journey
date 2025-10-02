class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = numBottles; // first drink all you have
        int empty = numBottles;
        while(empty>=numExchange){
            int bottle_toExchange = empty/numExchange; // bottles you can get
            int remaining_bottle = empty%numExchange; // leftover empty bottles

            totalDrank += bottle_toExchange;
            empty = bottle_toExchange+remaining_bottle;
        }
        return totalDrank;
    }
};