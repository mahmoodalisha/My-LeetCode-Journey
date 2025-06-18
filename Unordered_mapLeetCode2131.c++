class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mpp;  //We firstly store all the strings from words into a hashmap so that we can access their frequencies easily.
        for (string w : words) {
            mpp[w]++;
        }

        int count = 0;
        bool isPalindrome = false;

        for (auto& [w, freq] : mpp) {
            string s = w;
            reverse(s.begin(), s.end());

            if (w == s) {
                count += (freq / 2) * 4;
                if (freq % 2) isPalindrome = true;
            } else if (w < s && mpp.count(s)) {
                count += min(freq, mpp[s]) * 4;
            }
        }

        return count + (isPalindrome ? 2 : 0);
    }
};