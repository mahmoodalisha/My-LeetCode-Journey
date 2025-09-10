class Solution {
public:
    int MOD = 1e9+7;
    int t[301][301];
    int solve(int n, int num, int x){
        if(n == 0) return 1;

        if(n<0) return 0;

        int currentpower = pow(num, x);
        if(currentpower>n){ //base case pahuch gaya 
            return 0;
        }
        if (t[n][num] != -1){
            return t[n][num];
        }
        int take = solve(n-currentpower, num+1, x);
        int skip = solve(n, num+1, x);

        return t[n][num] = (skip+take)%MOD;
    }

    int numberOfWays(int n, int x) {
        memset(t,-1, sizeof(t));
        return solve(n, 1, x);
    }
};

//make the recursion tree youtube: code story with mik