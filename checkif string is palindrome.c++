// just check if the given string is pallindrome of not
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;   // 1st or the leftmost index of the string s
        int right = s.size() - 1;   // last or the rightmost index of the string s

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
