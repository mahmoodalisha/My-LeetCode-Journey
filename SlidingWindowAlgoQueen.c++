/*Given a string, find the length of the largest substring that has no repeated characters.

Sample 1
Input
s: "codedrills"

Output
5

Explanation
"edril" is the longest substring with no repeated characters

Sample 1
Input
s: "aabaecab"

Output
4

Explanation
"baec" is a substring of length 4 with all distinct characters*/

class Solution {
public:
    int longestDistinctSubstring(string s) {
        unordered_set<char> seen;
        int maxLen = 0, left = 0;
        for (int right = 0; right < s.length(); right++) {
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};