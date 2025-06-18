class Solution {
public:
    string reverseWords(string s) {
        //as per the ques i need to remove leading and trailing spaces first
        int start = 0;
        int end = s.length()-1;

        while(start<=end && s[start] == ' '){
            ++start;
        }
        while(end>=start && s[end] == ' '){
            --end;
        }

        vector<string> words;
        string word;
        for (int i = start; i <= end; ++i) {
            if (s[i] != ' ') {
                word += s[i];
            }
            if (s[i] == ' ' || i == end) {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            }
        }
        
        // Step 3: Build the reversed string
        string result;
        for (int i = words.size() - 1; i >= 0; --i) {
            if (!result.empty()) {
                result += ' ';
            }
            result += words[i];
        }
        
        return result;
    }
};