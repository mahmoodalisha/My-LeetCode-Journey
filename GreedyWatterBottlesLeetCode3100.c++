//only 1 exchange at a time
//2nd part of leetcode 1518
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int totalDrank = numBottles;
        int empty = totalDrank;

        while(empty>=numExchange){
            empty-=numExchange;
            totalDrank++; //we get only 1 new bottle with numExchange, we take that then we drink it
            empty++; //now add it with the empty bottles we have till now
            numExchange++;
        }
        return totalDrank;
    }
};