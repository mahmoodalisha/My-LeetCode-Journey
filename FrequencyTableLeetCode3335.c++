class Solution {
public:
    const int MOD = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector <long long> freq(26,0);

        for (int i = 0;i<s.length();i++){
            char c = s[i];
            freq[c - 'a']++;
        }
        for (int j = 0; j<t; j++){
            vector <long long> next_freq(26,0);
            for (int k = 0; k<26;k++){
                if (k == 25){
                    next_freq[0] = (next_freq[0]+freq[k])%MOD;
                    next_freq[1] = (next_freq[1]+freq[k])%MOD;
                }
                else{
                    next_freq[k+1] = (next_freq[k+1]+freq[k])%MOD;
                }
            }
            freq = next_freq;
        }
        long long total = 0;
        for (int i = 0; i<26;i++){
            total = (total+freq[i])%MOD;
        }
        return total;
    }
};