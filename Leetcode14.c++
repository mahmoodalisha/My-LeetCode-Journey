//Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        for (int i = 0; i<strs[0].size();i++){
            for (auto s:strs) {     //picking up any random string s from strs
                if (s[i]!=strs[0][i]){  //strs ka pehla index
                    return res;
                }
            }   
            res+=strs[0][i];
        }
        return res;
    }
};