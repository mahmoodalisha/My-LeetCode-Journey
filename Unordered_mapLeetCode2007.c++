class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> result;
        int n = changed.size();

        if(n%2 != 0){ //odd length ka array hai toh kisi na kisi element ka double hai hi nahi
            return {};
        }
        sort(changed.begin(), changed.end());

        unordered_map<int, int> freq;
        for(int& i : changed){
        freq[i]++;
        }

        for(int& i : changed){
            int twice = 2*i;
            if(freq[i] == 0) continue; //jis number pe khade hai uska frequency agar 0 hai toh age badho usko chhor do
            if(freq.find(twice) == freq.end() || freq[twice] == 0){//uska twice ko search karo agar nahi hai map me ya phir twice ki freq zero hai toh return kardo 
                return {};
            }
            result.push_back(i); //mil gaya toh push kardo
            freq[i]--; //kam karna padega nahi to duplicate ho jayega
            freq[twice]--; //kam karna padega nahi to duplicate ho jayega
        }
        return result;
    }
};

//youtube: code story with MIK