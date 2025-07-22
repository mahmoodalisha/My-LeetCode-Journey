class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_set<string> seen;
        unordered_set<string> repeated;

        for(int i = 0; i+9<n; i++){
            string sub = s.substr(i, 10);
                if(seen.count(sub)){
                    repeated.insert(sub);
                }
                else{
                    seen.insert(sub);
                }
            
        }
        return vector<string>(repeated.begin(), repeated.end()); //repeated ek set hai, 
        // aur return me hume chahiye vector<string>, kyunki function ka return type vector<string> hai toh convert kardo
    }
};