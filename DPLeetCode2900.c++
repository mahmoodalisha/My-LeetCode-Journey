words  = ["a", "b", "c", "d"]
groups = [1,   0,   1,   1]

Index	Word	Group	dp[i]	prev[i]
0	    "a"	      1	      1	      -1
1	    "b"	      0	      2	       0
2	    "c"	      1	      3	       1
3	    "d"	      1	      1	      -1

dp[2] = 3 hai, iska matlab alternating sequence bana 3 ka.
prev[2] = 1, prev[1] = 0, prev[0] = -1
So actual sequence = "a" -> "b" -> "c" (jo hum reverse karke nikaalte hain).

dp ka length milne ke baad hum kya karte hain?
🔹 Step 1: dp me sabse bada value dhoondho
Yani longest alternating subsequence ki length aur uska end index
int maxLen = 1;
int lastIndex = 0;

for (int i = 0; i < n; ++i) {
    if (dp[i] > maxLen) {
        maxLen = dp[i];         // sabse lamba sequence ki length
        lastIndex = i;         // vo sequence ka last element ka index
    }
}

| `i` | `j` | `groups[i]` | `groups[j]` | `dp[j] + 1` | `dp[i]` (before) | Update? | `dp[i]` (after) | `prev[i]` |
| --- | --- | ----------- | ----------- | ----------- | ---------------- | ------- | --------------- | --------- |
| 1   | 0   | 0           | 1           | 1+1 = 2     | 1                | ✅ Yes   | 2               | 0         |
| 2   | 0   | 1           | 1           | ✖️ same     |                  | ❌ No    |                 |           |
| 2   | 1   | 1           | 0           | 2+1 = 3     | 1                | ✅ Yes   | 3               | 1         |
| 3   | 0   | 1           | 1           | ✖️ same     |                  | ❌ No    |                 |           |
| 3   | 1   | 1           | 0           | 2+1 = 3     | 1                | ✅ Yes   | 3               | 1         |
| 3   | 2   | 1           | 1           | ✖️ same     |                  | ❌ No    |                 |           |

words  = ["a", "b", "c"]
groups = [1,   0,   1]

Step-by-step:
i = 2 (word = "c", group = 1)
Check karo j = 1 (word = "b", group = 0)
groups[2] != groups[1]   ✅groups[i] != groups[j]
dp[1] + 1 = 2 + 1 = 3    ✅ dp[j] + 1 > dp[i]
dp[2] = 1 initially
✅ 3 > 1 hai → toh update karo:

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
     int n = words.size();
    vector<int> dp(n, 1);     // dp[i] = max length of alternating sequence ending at i
    vector<int> prev(n, -1);  // to reconstruct the sequence

    int maxLen = 1, lastIndex = 0;

    // Build the dp and prev arrays
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (groups[i] != groups[j] && dp[j] + 1 > dp[i]) { //groups[i] != groups[j] → Alternating hona chahiye (0 ke baad 1 ya 1 ke baad 0)   Agar j se subsequence bana toh i tak ka length dp[i] se bada hoga.
                dp[i] = dp[j] + 1;      // Update kar do ki i tak ka subsequence ka length kya hai
                prev[i] = j;           // i se pehle j aaya tha, yaani j se i aaya
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    // Reconstruct the sequence
    vector<string> result;
    while (lastIndex != -1) {
        result.push_back(words[lastIndex]);
        lastIndex = prev[lastIndex];
    }

    reverse(result.begin(), result.end());
    return result;
    }
};