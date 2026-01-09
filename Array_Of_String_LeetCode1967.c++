/*
Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.
A substring is a contiguous sequence of characters within a string.


Example 1:

Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3
Explanation:
- "a" appears as a substring in "abc".
- "abc" appears as a substring in "abc".
- "bc" appears as a substring in "abc".
- "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.
*/


/*
1️⃣ Loop over patterns
for (string pattern : patterns)

👉 This loop chooses which pattern you are checking
(no index needed here)

2️⃣ i → starting index in word  for (int i = 0; i <= n - m; i++)
Example: word = "abc"
i = 0 → start at 'a'
i = 1 → start at 'b'
👉 i means: “Try to match the pattern starting at position i in word”

3️⃣ j → index inside pattern
👉 j means: “Compare characters of the pattern one by one”
*/

/*
👉 i Starting position in word where we try to match the pattern.

👉 j Current index inside pattern (and also how far we’ve matched so far).
 */
class Solution {
public:
    bool isSubstring(string& word, string& pattern){ //iterating inside the strings and not array of string for patterns !!
        int n = word.size();
        int m = pattern.size();

        for(int i = 0; i <= n-m; i++){ //i only changes after matching fails or completes.
            int j = 0;

            while(j<m && word[i+j] == pattern[j]){ //pattern[0] matched so move to the next character in the pattern
                j++; //move to the next charater in pattern 
            }
            if(j == m){
                return true; //full pattern matched
            }
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(string pattern : patterns){
            if(isSubstring(word, pattern)){
                count++;
            }
        }
        return count;
    }
};

/*
Example
word    = "abc"
pattern = "bc"

Try matching at i = 1

| j (before) | Compare                        | Result | j (after) |
| ---------- | ------------------------------ | ------ | --------- |
| 0          | word[1] vs pattern[0] → b vs b | match  | 1         |
| 1          | word[2] vs pattern[1] → c vs c | match  | 2         |

*/