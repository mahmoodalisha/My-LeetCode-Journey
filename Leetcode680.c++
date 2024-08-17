class Solution {
    //this public function allows you to delete at most one charater from the string if it is pallindrome
public:
    bool validPalindrome(string s) {
        int left = 0;   // 1st or the leftmost index of the string s
        int right = s.size() - 1;   // last or the rightmost index of the string s

        while (left < right) {
            if (s[left] != s[right]) {

                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }  //this return line allows you to delete at most one character from the string if the string is pallindrome
            left++;
            right--;
        }
        return true;
    }

//this pvt function simply checks if the string is pallindrome or not
private:
    bool isPalindrome(const string& s, int left, int right) {
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
