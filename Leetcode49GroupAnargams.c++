class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //traverse through vector and sort each string and add strs[i] to the sorted string
        //store the ans in vector of vector
        map<string, vector<string>>mp;
        for(int i = 0;i<strs.size();i++){
            string s = strs[i]; //har ek string ko leke sort karri hu, kyunki sorted ki same anargam hoga
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]); 
        }
            //step 2. storing the answer, size of the answer will be the no. of rows in mp
            vector<vector<string>> ans(mp.size());
            int index = 0;
            for(auto j:mp){
                auto temp = j.second;
                for(auto j:temp){
                    ans[index].push_back(j);
                }
            
            index++;
        }
        return ans;
    }
};