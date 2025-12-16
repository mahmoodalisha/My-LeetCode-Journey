/*
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.
Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

Example 1:
Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1

Example 2:
Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3
*/

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> mpp;
        int count = 0;

        for(auto &d : dominoes){
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
        
        int key = (a * 10) + b; //encode together

        count += mpp[key];
        mpp[key]++;
        }
        return count;
    }
};




/* 
[1,2] ≡ [2,1]
[3,4] ≡ [3,4]
Order does NOT matter
Normalization means converting different-looking but equivalent things into ONE fixed form
For dominoes:
[1,2] and [2,1] should be treated the same
So we always store them in sorted order

a = min(d[0], d[1]);
b = max(d[0], d[1]);
Now:
[2,1] → (1,2)
[1,2] → (1,2)

👉 Both become identical.
That is normalization.
*/


/*
dominoes = [[1,2],[2,1],[1,2]]
| Domino | Normalized | Key | mpp before | count added |
| ------ | ---------- | --- | ---------- | ----------- |
| [1,2]  | (1,2)      | 12  | 0          | +0          |
| [2,1]  | (1,2)      | 12  | 1          | +1          |
| [1,2]  | (1,2)      | 12  | 2          | +2          |

 */