//leetcode 1903
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.length()-1; i>=0; i--){
            if((num[i]%2) != 0){
                return num.substr(0,i+1);  //from 0 to that position add the substring
            }
        }
        return "";
    }
};

======================================================================================================
//Subtring Problem
//either of the strings can be substrings of each other
//So s1 can be smaller than s2 and s2 can also be smaller than s1
//This is brute force TC: O(mxn)
bool isSubstring(string s1, string s2) {

    // Determine which string is longer
    //Text = the string you are searching inside (the larger string)
    //Pattern = the string you are trying to find (the smaller string)
    string text, pattern;

    if (s1.size() >= s2.size()) {
        text = s1;
        pattern = s2;
    } else {
        text = s2;
        pattern = s1;
    }

    int n = text.size();
    int m = pattern.size();

    // Brute-force substring search
    for (int i = 0; i <= n - m; i++) {

        int j = 0;

        while (j < m && text[i + j] == pattern[j])
            j++;

        if (j == m)
            return true;
    }

    return false;
}
//optimised solution of the subtring problem would be KMP algo, whose TC is O(m+n)
//KMP algo follows the Longest Prefix Suffix approach (LPS)
=====================================================================================================

//Two Pointer approach for finding subsequence TC: O(n) 
//already optimized
bool isSubsequence(string s1, string s2) {

    // Determine which string is longer
    string text, pattern;

    if (s1.size() >= s2.size()) {
        text = s1;
        pattern = s2;
    } else {
        text = s2;
        pattern = s1;
    }

    int i = 0; // pointer for text
    int j = 0; // pointer for pattern

    while (i < text.size() && j < pattern.size()) {

        if (text[i] == pattern[j])
            j++;

        i++;
    }

    return j == pattern.size();
}

/* s1 = "foobar"

| s2    | Subsequence?       |
| ----- | ------------------ |
| "fbr" | ✅ Yes              |
| "far" | ✅ Yes              |
| "foo" | ✅ Yes              |
| "bar" | ✅ Yes              |
| "frb" | ❌ No (wrong order) |
| "rab" | ❌ No               |


*/