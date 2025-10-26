/* Two Pointer Approach
Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.
You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

Example 1:
Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.

Example 2:
Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it was not in the typed output.

Dry Run Example
name = "alex"
typed = "aaleex"
| Step | name[i] | typed[j] | Match            | Action         |
| ---- | ------- | -------- | ---------------- | -------------- |
| 1    | a       | a        | ✅                | i=1, j=1       |
| 2    | l       | a        | ❌ but long-press | j=2            |
| 3    | l       | l        | ✅                | i=2, j=3       |
| 4    | e       | e        | ✅                | i=3, j=4       |
| 5    | e       | e        | ❌ but long-press | j=5            |
| 6    | x       | x        | ✅                | i=4, j=6 (end) |

*/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0; //pointer to track name
        int j = 0; //pointer to track typed

        while(j<typed.size()){
            if(i<name.size() && name[i] == typed[j]){
                // Same character, move both
                i++;
                j++;
            }
            else if(j>0 && typed[j] == typed[j-1]){
                // Long press case: same as previous typed character
                j++;
            }
            else {
                // Invalid character
                return false;
            }
        }
        // If we've processed all of name, it’s valid
        return i == name.size();
    }
};
/*
❌ Example of failure
name = "alex"
typed = "aaleexa"

At the end:
i = 4 (done with name)
j = 7 (extra "a" left in typed)
That’s fine — extra long presses are allowed.

But if we had:

name = "alex"
typed = "aale"

Then:
i = 3

name.size() = 4
So:

return i == name.size(); // false

Because we never reached ‘x’ — not fully typed!
*/