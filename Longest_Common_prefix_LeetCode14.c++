/*
| Expression   | Meaning                        | Example (in this case)       |
| ------------ | ------------------------------ | ---------------------------- |
| `strs`       | Vector of strings              | {"flower", "flow", "flight"} |
| `strs[0]`    | First string                   | "flower"                     |
| `strs[0][i]` | i-th character of first string | For i=1 → 'l'                |

i=0   i=1   i=2   i=3 ...
s="flower"   f      l      o      w
s="flow"     f      l      o      w
s="flight"   f      l      i      g



🧩 Think of it like a table of letters

Imagine your array strs as a table:
| Index | String   | Characters (indexed by i)                |
| ----- | -------- | ---------------------------------------- |
| 0     | "flower" | f (0), l (1), o (2), w (3), e (4), r (5) |
| 1     | "flow"   | f (0), l (1), o (2), w (3)               |
| 2     | "flight" | f (0), l (1), i (2), g (3), h (4), t (5) |

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        for(int i = 0; i<strs[0].size(); i++){
            for(auto s : strs){
                if(s[0] != strs[0][i]){
                    return result;
                }
            }
            result += strs[0][i];
        }
        return result;
    }
};

//now the optimized one
//compare only the first and the last string
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string result = "";
        string first = strs.front();
        string last = strs.back();
        for(int i = 0; i<first.size() && i<last.size(); i++){
            if(first[i] != last[i]){
                return result;
            }
            else{
                result += first[i];
            }
        }
        return result;
    }
};