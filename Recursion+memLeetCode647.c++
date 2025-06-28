class Solution {
public:
    int t[1001][1001]; //memoization
    bool check(string &s, int i, int j){
        if(i>j) return true; //out of bound ho gaya humne saare character check kar liye
        if(t[i][j] != -1){ //-1 matlab abhi tak solve nai hai
        return t[i][j];
        }
        if(s[i] == s[j]){ //agar equal hai toh further baaki logo ko check karlo
        return t[i][j] = check(s, i+1, j-1);
        }
        return t[i][j] = false;
    }
    int countSubstrings(string s) {
        int n = s.length();
        memset(t,-1, sizeof(t));
        //t[i][j] = 0 hai to false hai wo log palindrome nahi hai
        //t[i][j] = 1 hai to palindrome hai
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if (check(s, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};
//TC: O(n^2)