class Solution {
public:
    int beautySum(string s) {
        int total = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> myfreq;
            for (int j = i; j < n; j++) {
                myfreq[s[j]]++;

                int maxfreq = 0;
                int minfreq = INT_MAX;

                for (auto& [ch, count] : myfreq) {
                    maxfreq = max(maxfreq, count);
                    if (count > 0) {
                        minfreq = min(minfreq, count);
                    }
                }

                total += maxfreq - minfreq;
            }
        }
        return total;
    }
};



/* 

All possible substrings (from i to j):

i	j	Substring
0	0	"a"
0	1	"aa"
0	2	"aab"
1	1	"a"
1	2	"ab"
2	2	"b"

freq = {
    'a' → 2,
    'b' → 2,
    'c' → 1
}

for (auto& [ch, count] : freq)
First Iteration:
ch = 'a'
count = 2 (kyunki 'a' 2 baar aaya hai)

Second Iteration:
ch = 'b'
count = 1 (kyunki 'b' 1 baar aaya hai)

Input s = "aabcb"
1. a      →                         → beauty = 0
2. aa     → 'a':2                   → beauty = 2-2 = 0
3. aab    → 'a':2, 'b':1            → beauty = 2-1 = 1 ✅
4. aabc   → 'a':2, 'b':1, 'c':1     → beauty = 2-1 = 1 ✅
5. aabcb  → 'a':2, 'b':2, 'c':1     → beauty = 2-1 = 1 ✅
6. a      →                         → beauty = 0
7. ab     → 'a':1, 'b':1            → beauty = 1-1 = 0
8. abc    → 'a':1, 'b':1, 'c':1     → beauty = 1-1 = 0
9. abcb   → 'a':1, 'b':2, 'c':1     → beauty = 2-1 = 1 ✅
10. b     →                         → beauty = 0
11. bc    → 'b':1, 'c':1            → beauty = 1-1 = 0
12. bcb   → 'b':2, 'c':1            → beauty = 2-1 = 1 ✅
13. c     → 0                       → beauty = 0
14. cb    → 'c':1, 'b':1            → beauty = 1-1 = 0
15. b     → 0                       → beauty = 0

1 + 1 + 1 + 1 + 1 = 5
 */