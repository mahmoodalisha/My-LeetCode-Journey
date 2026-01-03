/* Combinations:- Dynamic Programming
You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).
Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.
*/
//n given rows hai aur column fixed hai matlab 3 hi column hai
//Similar advanced question :- LeetCode 1931
//main ith Row pe khada hu toh (i-1)th row ki help se ith row ka answer nikaal sakta hu

//n given rows hai aur column fixed hai matlab 3 hi column hai
//Similar advanced question :- LeetCode 1931
//main ith Row pe khadi hu toh (i-1)th row ki help se ith row ka answer nikaal sakti hu
//prev row ka ith index pe jo color hai wo current row ke ith index ke color ke barabar toh nahi hai nah...check karte jaao conflict hai ya nahi
class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> t; //2 cheeze change ho rhi hai n aur prev

    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"}; //12 possible first rows
    int solve(int n, int prev){
        //base case
        if(n==0) return 1; //saare rows paint kar diye ab koi row nahi bacha paint karne ke liye
        if(t[n][prev] != -1) return t[n][prev];
        int result = 0;
        string last_row = states[prev]; //pichle row ko maine kis pattern se paint kiya tha
        for(int curr_row = 0; curr_row<12; curr_row++){
            if(curr_row == prev)
                continue;
            string curr_pattern = states[curr_row];
            bool conflict = false;
            for(int col = 0; col<3; col++){
                if(curr_pattern[col] == last_row[col]){
                    conflict = true;
                    break;
                }
            }
            if(!conflict){
                result = (result + solve(n-1, curr_row))%MOD;
            }
        }
        return t[n][prev] = result;
    }
    int numOfWays(int n) {
        t.resize(n, vector<int>(12, -1));
        int result = 0;
        for(int curr_idx = 0; curr_idx<12; curr_idx++){ //choosing 1st row
            //now remaining n-1 rows painting
            result = (result+solve(n-1, curr_idx))%MOD;
        }
        return result;
    }
};
//youtube : code story with MIK
//T.C : O(n)