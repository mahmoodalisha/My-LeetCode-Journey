class Solution {
public:
    int n;
    int t[501][501];
    int solve(string &s, int i, int j){
        if(i>=j) return 0; //matlab khatam end tak aa gaye
        if(t[i][j]!= -1)
        return t[i][j];
        if(s[i] == s[j]) return solve(s, i+1, j-1);//aage badho
        return t[i][j] =  1+min(solve(s,i+1, j), solve(s,i,j-1));
    }
    int minInsertions(string s) {
        n = s.length();
        memset(t, -1, sizeof(t));
        return solve(s, 0, n-1); //i zero se start hoga aur j last matlb n-1 se, all dry run in my DSA copy
    }
};