/* calculating index of characters with the help of their ascii and then finally updating the frequency
| Step | Character (`c`) | ASCII of `c` | `'a'` ASCII | `c - 'a'` (Index) | What happens                | Updated `freq` snippet                            |
| ---- | --------------- | ------------ | ----------- | ----------------- | --------------------------- | ------------------------------------------------- |
| 1    | `'a'`           | 97           | 97          | 0                 | `freq[0]++` → `freq[0]=1`   | `[1, 0, 0, 0, ...]`                               |
| 2    | `'p'`           | 112          | 97          | 15                | `freq[15]++` → `freq[15]=1` | `[1, 0, ..., 1 (at index 15)]`                    |
| 3    | `'p'`           | 112          | 97          | 15                | `freq[15]++` → `freq[15]=2` | `[1, 0, ..., 2 (at index 15)]`                    |
| 4    | `'l'`           | 108          | 97          | 11                | `freq[11]++` → `freq[11]=1` | `[1, 0, ..., 1 (at index 11)]`                    |
| 5    | `'e'`           | 101          | 97          | 4                 | `freq[4]++` → `freq[4]=1`   | `[1 (a), 0, 0, 0, 1 (e), ..., 1 (l), ..., 2 (p)]` |


| Letter | a | b | c | d | e | f | g | h | i | j | k | l | m | n | o | p | q | r | s | t | u | v | w | x | y | z |
| ------ | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |
| Count  | 1 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

*/


//Rule is that you will have to do exactly one swap ! 
//even if s == goal you will have to swap and see whether after doing one swap we are able to get goal just like in example 2 where s = "ab" and goal = "ab"
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;

        if(s == goal){
            vector<int> freq(26, 0);
            for(char c : s){
                freq[c - 'a']++;
                if(freq[c - 'a'] > 1) return true; //duplicates found
            }
            return false;
        }
        //now case 2 to find mismatched pairs
        int first = -1, second = -1;
        for(int i = 0; i<s.size(); i++){
            if(s[i] != goal[i]){
                if(first == -1) first = i;
                else if(second == -1) second = i;
                else return false; //more than two difference
            }
        }
        //now lets check if one valid swap makes strings equal

        return (second != -1 && s[first] == goal[second] && s[second] == goal[first]);
        
    }
};