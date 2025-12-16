/*
Example 1:
Input: s1 = "this apple is sweet", s2 = "this apple is sour"
Output: ["sweet","sour"]
Explanation:
The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:
Input: s1 = "apple apple", s2 = "banana"
Output: ["banana"]
*/

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> result;
        string word;
        unordered_map<string, int> freq;

        //process s1
        stringstream ss1(s1);
        while(ss1 >> word){
            freq[word]++;
        }

        //process s2
        stringstream ss2(s2);
            while(ss2 >> word){
                freq[word]++;
            }

            //collect uncommon words
            for(auto &p : freq){
                if(p.second == 1){
                    result.push_back(p.first);
                }
            }
        return result;
    }
};

//p.first → the word
//p.second → how many times it appeared

/*
s1 = "apple banana apple"
s2 = "banana orange"

freq = {
    "apple": 2,
    "banana": 2,
    "orange": 1
}

*/