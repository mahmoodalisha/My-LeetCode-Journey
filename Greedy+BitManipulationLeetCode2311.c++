class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int zeroes = 0; //starting me kitne zeroes hai string me
        int ones = 0; //starting me kitne ones hai string me
        int value = 0; //val me add karte jaana
        int pow = 1;

        for(char c:s){
            if(c == '0') zeroes++;
        }
        for(int i = n-1; i>=0; i--){//start from RHS
            if(s[i] == '1'){
                if (value+pow>k) continue;
                value += pow;
                ones++;
            }
            pow <<= 1;
            if(pow>k) break; //k se bada hai to aage jaane ki zarurat hi nahi hai
        }
        return zeroes+ones;
    }
};

//youtube: coding grower
//Check DSA copy for dry run