/* Easy
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minFreq(26, INT_MAX);

        for(auto &word : words){
            vector<int> freq(26, 0);
            for(char c : word){
                freq[c - 'a']++;
            }
            for(int i = 0; i<26; i++){
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }
        vector<string> result;
        for(int i = 0; i<26; i++){
            while(minFreq[i]-- > 0){
                result.push_back(string(1, char(i+'a')));
            }
        }
        return result;
    }
};

/*
freq array stores frequency of letters in one word.
Example word = "bella"
freq would be:
a:0
b:1
e:1
l:2

minFreq stores minimum frequency of each character across all words.
*/