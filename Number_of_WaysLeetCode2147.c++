//find the total number of ways such that we have 2 seats in each half
class Solution {
public:
    int numberOfWays(string corridor) {
        int MOD = 1e9 + 7;
        long long ways = 1;

        int seats = 0;
        int plants = 0;
        bool started = false;
        for(char c : corridor){
            if(c == 'S'){
                seats++;

                if(seats > 2 && seats%2 == 1){
                    ways = (ways * (plants + 1))%MOD;
                    plants = 0;
                }
                started = true;
            } else if(started && seats % 2 == 0){
                plants++;
            }
        }
        //total number of seats must be evem then only we will be able to divide the seats into 2 such halves
        if(seats < 2 || seats%2 != 0) return 0;
        return ways;
    }
};