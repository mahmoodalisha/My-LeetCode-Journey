class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> vec(n,0);
        vec[0] = values[0]+0; //that formula in my copy

        for(int i = 1; i<n; i++){
            vec[i] = max(values[i]+i, vec[i-1]); //ab tak jo maximum dekha hai wo ya phir abhi jo value hai wo max hai
        }
        int result = 0;

        for(int j = 1; j<n; j++){
            int x = values[j]-j;
            int y = vec[j-1]; //max value of (values[i]+i on left hand side of j)

            result = max(result, x+y);
        }
        return result;
    }
};
//youtube: code story with MIK
//for dry run check DSA copy