int fib(int n, vector<int> &dp){
    if(n <=1) //base case
    return n;

    if dp[n] != -1;
    return dp[n];

    dp[n] = fib(n-1) + fib(n-2); //step 3
    return dp[n]
}