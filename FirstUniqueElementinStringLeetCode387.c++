class Solution {
public:
    int firstUniqChar(string s) {
        // Step 1: Frequency array (26 letters)
        int freq[26] = {0};
        for(char c : s){
            freq[c - 'a']++;
        }

        // Step 2: Find first character with freq 1
        for(int i = 0; i < s.size(); i++){
            if(freq[s[i] - 'a'] == 1)
                return i; // first unique char index
        }

        return -1; // no unique char found
    }
};
