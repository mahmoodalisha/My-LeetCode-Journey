class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Base case: empty string ko 1 tareeke se decode kar sakte hain
    dp[1] = 1; // Agar first character valid hai (0 nahi hai), toh 1 tareeka hai
    
    for (int i = 2; i <= n; ++i) { //Loop 2 se start isliye ho raha hai kyunki dp[0] aur dp[1] pehle hi set kar diya.
        int oneDigit = s[i - 1] - '0'; // ek digit check kar rahe hain s[i-1] (ek digit) kya valid hai (1–9)?
        int twoDigit = stoi(s.substr(i - 2, 2)); // do digit check kar rahe hain s[i-2] + s[i-1] (do digit milake) kya valid hai (10–26)?
        
        //Agar ek digit valid hai (0 nahi), toh uske pehle tak jitne tareeke hain, woh yahan bhi chalenge.
        if (oneDigit >= 1 && oneDigit <= 9)
            dp[i] += dp[i - 1];
        
        //Agar do digits milake valid letter ban rahe hain, toh unke pehle tak jitne tareeke hain, woh bhi yahan add honge.
        if (twoDigit >= 10 && twoDigit <= 26)
            dp[i] += dp[i - 2];
    }
    return dp[n];
    }
};