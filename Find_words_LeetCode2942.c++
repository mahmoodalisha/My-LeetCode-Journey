class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector <int> result;
        for(int i = 0; i<words.size(); i++){
            if(words[i].find(x) != string::npos){
                result.push_back(i);
            }
        }
        return result;
    }
};

/* words[i] accesses the i-th string in the words vector
.find(x) looks for the first occurrence of character x in that string.
If x is found, find() returns its index (e.g., 0, 1, etc.)
If x is not found, find() returns string::npos, which is a constant meaning “not found”.
*/