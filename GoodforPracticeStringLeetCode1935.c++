class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> seen(brokenLetters.begin(), brokenLetters.end());
        bool canType = true;
        int count = 0;
        
        for(int i = 0; i<=text.size(); i++){
            if(i == text.size() || text[i] == ' '){
                if(canType)
                    count++;
                    canType = true; // reset for next word
            } else if(seen.count(text[i])){
                canType=false;
            }
        }
        return count;
    }
};