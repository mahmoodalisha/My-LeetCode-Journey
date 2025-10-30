class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26, 0);

        for(char &c : s){
            freq[c - 'a']++;
        }

        for(char &ch : t){
            freq[ch - 'a']--;
                if(freq[ch - 'a']<0){
                    return ch;
            }
        }
        return ' ';
    }
};
/*
s = "aabc"
'a' → freq[0] = 1
'a' again → freq[0] = 2
'b' → freq[1] = 1
'c' → freq[2] = 1
Suppose t = "aacbc" (note: extra 'c' at the end)
First 'a' → freq[0] = 1
Second 'a' → freq[0] = 0
'c' → freq[2] = 0
'b' → freq[1] = 0
'c' again → freq[2] = -1 ❗ negative → this is the extra character
*/