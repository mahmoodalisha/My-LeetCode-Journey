class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> chartoword;
        unordered_map<string, char> wordtochar;

        int i = 0, n = s.size();
        for(char c : pattern){
            while(i<n && s[i] == ' ') i++;
                if(i>= n) return false; //fewer words than pattern
                //now extract one word
                int start = i;
                while(i<n && s[i] != ' ')
                i++;
                string word = s.substr(start, i-start);

                if(chartoword.count(c) && chartoword[c] != word) return false;
                if(wordtochar.count(word) && wordtochar[word] != c) return false;

                chartoword[c] = word;
                wordtochar[word] = c;
            }
            while(i<n && s[i] == ' ') i++;
            if(i<n) return false;
            return true;
    }
};
/*
Instead of looping over s directly and separately tracking the current pattern index,
we simply loop over the pattern characters and use an index i to extract the next word from s at the same time. 

This means for each character in pattern, extract one word from s (using the pointer i).


unordered_map<char, string> chartoword;
chartoword['a'] = "dog";
chartoword['b'] = "cat";

.count(key) tells us whether the key exists in the map

chartoword.count(c) → check if c already has a mapped word.

If false, c is new → we can assign it.
If true, c has already been assigned some word before.
chartoword[c] != word → check if the current word matches the word we already stored for this pattern character.
If mismatch → violates the pattern → return false
 */