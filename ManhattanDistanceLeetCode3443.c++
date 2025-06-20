class Solution {
public:
    int maxDistance(string s, int k) {
        int maxMD = 0;

        int north = 0;
        int south = 0;
        int east = 0;
        int west = 0;

        for(int i = 0; i<s.length(); i++){
            if (s[i] == 'E') east++;
            else if(s[i] == 'W') west++;
            else if(s[i] == 'N') north++;
            else if(s[i] == 'S') south++;

            int currentMD = abs(east-west) + abs(north-south);
            int steps = i+1;
            int wastedsteps = steps - currentMD;

            int extra = 0;
            if(wastedsteps != 0){ //steps is not equal to manhattan distance
            extra = min(2*k, wastedsteps);
            }
            int finalcurrentMD = currentMD + extra;
            maxMD = max(maxMD, finalcurrentMD);
        }
        return maxMD;
    }
};