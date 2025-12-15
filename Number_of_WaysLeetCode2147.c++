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
/*
started means “have we seen the first seat yet?”
We only want to count plants between seat pairs, not before the first seat.

input corridor = "PPPSSPPS"
| char | seats | started | plants | reason           |
| ---- | ----- | ------- | ------ | ---------------- |
| P    | 0     | false   | 0      | ignored          |
| P    | 0     | false   | 0      | ignored          |
| P    | 0     | false   | 0      | ignored          |
| S    | 1     | true    | 0      | first seat       |
| S    | 2     | true    | 0      | section complete |
| P    | 2     | true    | 1      | valid plant      |
| P    | 2     | true    | 2      | valid plant      |
| S    | 3     | true    | reset  | multiply         |


2️⃣ Why do we reset plants?
Short answer:
Each gap between seat-pairs is independent.
So yes - after each multiplication, we reset plants to 0.
*/

/*
One-line summary (memorize this)

started → ignore plants before the first seat

plants → count plants only between seat-pairs

plants = 0 → reset after finishing one gap

multiplication → happens when next section starts
*/