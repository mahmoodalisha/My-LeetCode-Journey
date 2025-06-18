class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mpp;

        for(char num : mpp){
            mpp[num]++;
        }

        int maxodd = INT_MIN;
        int mineven = INT_MAX;

        for(auto& i : mpp){
            int f = i.second;

            if(f%2 == 0){
                mineven = min(mineven, f);
            }
            else{
                maxodd = max(maxodd, f);
            }
        }
        return (maxodd - mineven);
    }
};