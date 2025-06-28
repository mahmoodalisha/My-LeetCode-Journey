class Solution {
public:
    bool ifexists(string s, string p, int k){ //you have string and if one string is repeated k times in another string or not
    string str = "";
    while(k--) str += p;
    int j = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i]==str[j]){ //check for sub sequence
            j++;
        }
        if(j==str.size()) break; //u got the sub sequence
    }
    return j == str.size();
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vector<int> freq(26);
        for(auto c : s) freq[c-'a']++;
        for(int i = 0; i<26; i++){
            if(freq[i]<k){
                freq[i] = 0;
            }
            else{
                freq[i]/=k;
            }
        }
        queue<string> q;
        q.push("");
        string ans;
        while(!q.empty()){
            string str = q.front(); q.pop();
            vector<int> n_freq = freq; //update it with the old frequency
            for(auto x : str){
                n_freq[x - 'a']--;
            }
            for(int i = 25; i>=0; i--){//check from the back so you will get the lexicographically larger one
            if(n_freq[i]==0) continue;
            char c = i+'a';
                string temp = str + c;
                if(ifexists(s,temp,k)){
                    q.push(temp); //keep on appending
                    if(temp.size()>ans.size()){ 
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
};
//youtube: eye on AI and DSA