class Solution {
public:
    static bool compare(string &a, string &b) {
        return a.length() < b.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare); // sort by word length
        unordered_map<string, int> dp;
        int maxLen = 1;

        for (string word : words) {
            int best = 0;

            for (int i = 0; i < word.length(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1); // remove one char
                best = max(best, dp[prev]); // check if prev exists in map, agar dp[prev] exist karta hai toh chain ka length le lo
            }

            dp[word] = best + 1; //agar mujhe prev mil gaya toh, main word ko us chain mein add kar deta hoon
            maxLen = max(maxLen, dp[word]); // update global max
        }

        return maxLen;
    }
};
/*
prev is the previous word (or potential predecessor word) in the chain.
Variable	                Purpose
prev	                    Creates possible predecessor words by removing one char
dp[prev]	                Checks if any of those predecessors exist in the chain
best	                    Stores the max chain length among all valid predecessors
dp[word] = best + 1	        Builds the current chain by adding this word
maxLen	                    Keeps track of the overall longest chain seen so far
*/
/*
dp["a"] = 1;
dp["ba"] = dp["a"] + 1 = 2;
dp["bda"] = dp["ba"] + 1 = 3;
dp["bdca"] = dp["bda"] + 1 = 4;
Iska matlab "a" → "ba" → "bda" → "bdca" is the longest chain 
*/