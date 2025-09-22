class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> myfreq;
        int maxfreq = 0;
        
        for(int i : nums){
            myfreq[i]++;
            maxfreq = max(maxfreq, myfreq[i]); //to keep track of maxfreq
        }
        //now count how many elements have that max freq
        int result = 0;
        for(auto& [key, value] : myfreq){
            if(value == maxfreq){
                result += value; //we are appending the count
            }
        }
        return result;
    }
};