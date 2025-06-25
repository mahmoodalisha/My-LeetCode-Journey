class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long chalkSum = 0;
        for(int num : chalk){
            chalkSum += num;
        }
        int remainingChalk = k%chalkSum;

        for(int i = 0; i<n; i++){
            if(remainingChalk<chalk[i]){
                return i;
            }
            remainingchalk -= chalk[i];
        }
        return -1;
    }
};