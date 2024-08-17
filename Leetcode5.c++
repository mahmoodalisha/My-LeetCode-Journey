//Longest Pallindromic Substring Leetcode #5
//start from the middle of the given string, there will be two conditions, either the string is odd or the sstring is even
//check gallery screenshots in this laptop
class Solution {
    private:
    int expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLength = 1;

        for (int i = 0; i < s.length(); ++i) {
            // Check for odd length palindromes
            int len1 = expandAroundCenter(s, i, i);
            // Check for even length palindromes
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }

    
};