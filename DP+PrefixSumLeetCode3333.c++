class Solution {
public:
    int MOD = 1e9+7;

    int possibleStringCount(string word, int k) {
        vector<int> groups;
        int cnt = 1;
        //step1: group the charecters
        for (int i = 1; i < word.size(); i++) {
    if (word[i] == word[i - 1]) {
        cnt++;
    } else {
        groups.push_back(cnt);  // push when group ends
        cnt = 1;
    }
}
groups.push_back(cnt);  // push the last group

        int G = groups.size();
        // Step 2: Total possibilities = product of each group length
        long long total = 1;
        for(int g : groups){
            total = (total*g)%MOD;
        }
        // If we can already make at least k-length original strings
        if (k <= G) return total;
        // Step 3: Count #invalid original strings of length < k
        vector<long long> dp(k, 0); // dp[i] = ways to get length i
        dp[0] = 1;
        for(int g : groups){
            vector<long long> new_dp(k, 0);
            vector<long long> prefix(k + 1, 0);  // prefix sum for range queries
            for (int i = 0; i < k; ++i) {
                prefix[i + 1] = (prefix[i] + dp[i]) % MOD;
            }
            for (int i = 1; i < k; ++i) {
                int l = max(0, i - g);
                int r = i;
                new_dp[i] = (prefix[r] - prefix[l] + MOD) % MOD;
            }
            dp = new_dp;
        }
        long long invalid = 0;
        for (int i = 0; i < k; ++i) {
            invalid = (invalid + dp[i]) % MOD;
        }

        return (total - invalid + MOD) % MOD;
        }
};