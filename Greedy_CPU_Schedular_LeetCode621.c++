class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26, 0); //normal array to store the frequencies this isnt map
        for(char &ch : tasks){
            mpp[ch - 'A']++;
        }
        sort(mpp.begin(), mpp.end()); //a to z ki frequency mil jaye toh sort kar lo

        int maxFreq = mpp[25]; //jiski sabse zyada frequency hogi wo last me milega kyunki ascending order me sort kiya hai
        int gap = maxFreq-1;
        int slotintervals = n*gap;
        for(int i = 24; i>=0; i--){
            slotintervals -= min(mpp[i], gap);
        }
        if(slotintervals>0){
            return tasks.size()+slotintervals;
        }
        return tasks.size();
    }
};
//youtube : code story with MIK
/*

tasks = ['A','A','B','C','C','C']

mpp[0] = 2      'A' count
mpp[1] = 1      'B' count
mpp[2] = 3      'C' count
*/