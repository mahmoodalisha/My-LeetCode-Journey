class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int i : arr){
            freq[i]++;
        }
        unordered_set<int> seen;
        for(auto& [num, count] : freq){
            if(seen.find(count) != seen.end()){
                //frequency already exists not unique
                return false;
            }
            seen.insert(count);
        }
        return true;
    }
};