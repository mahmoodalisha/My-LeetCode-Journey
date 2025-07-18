class Solution {
public:
    int mn = INT_MAX;  // should start with INT_MAX
    int mx = INT_MIN;  // should start with INT_MIN
    int N = 0;
    int f = 0;
    int s = 0;
    int dp[27][27][27];

    void cal(int mask, int round, int i, int j, int l, int m, int r){
        if(i >= j) {
            // next round starts, recreate the bitmask of surviving players
            int new_mask = 0;
            for(int k = 0; k <= N; ++k) {
                if(mask & (1 << k)) {
                    new_mask |= (1 << k);
                }
            }
            // recurse from beginning of next round
            cal(new_mask, round + 1, 0, N, l, m, r);
            return;
        }

        if((mask & (1 << i)) == 0) {
            cal(mask, round, i + 1, j, l, m, r);
            return;
        }

        if((mask & (1 << j)) == 0) {
            cal(mask, round, i, j - 1, l, m, r);
            return;
        }

        if(i == f && j == s) {
            mn = min(mn, round);
            mx = max(mx, round);
            return;
        }

        if(dp[l][m][r] != -1) return;
        dp[l][m][r] = 1;

        if(i != f && i != s){
            cal(mask ^ (1 << i), round, i + 1, j - 1, l - (i < f), m - ((i > f) && (i < s)), r - (i > s));
        }

        if(j != f && j != s){
            cal(mask ^ (1 << j), round, i + 1, j - 1, l - (j < f), m - ((j > f) && (j < s)), r - (j > s));
        }
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        N = n - 1;
        f = firstPlayer - 1;
        s = secondPlayer - 1;
        memset(dp, -1, sizeof(dp));
        cal((1 << n) - 1, 1, 0, n - 1, f, s - f - 1, N - s);
        return {mn, mx};
    }
};
//youtube : eye on AI and DSA