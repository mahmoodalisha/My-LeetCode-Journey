class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int>mpp; 
            for(char num : s){
                mpp[num]++;
            }
        

        int maxodd = INT_MIN;
        int mineven = INT_MAX;

        for(auto& i : mpp){
            int freq = i.second;
            
            if(freq%2 == 0){
                mineven = min(mineven, freq);
            }
            else {
            maxodd = max(maxodd, freq);
            }
        }
        return (maxodd-mineven);
    }
};