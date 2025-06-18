/*
Rules (niyam) kya hain?
Zinda cell:
Agar 2 se kam zinda neighbours hain, to wo mar jaata hai (under-population).
Agar 2 ya 3 zinda neighbours hain, to wo zinda ho jata hai.
Agar 3 se zyada zinda neighbours hain, to wo mar jaata hai (over-population).

Mara hua cell:
Agar uske exactly 3 zinda neighbours hain, to wo zinda ho jaata hai (reproduction).

✅ Tumse kya maanga gaya hai?
Tumhe ye rules apply kar ke board ko next state me update karna hai.
Board simultaneously update hona chahiye, yani kisi cell ko update karne se doosre cells ke update par asar nahi padna chahiye.

*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int live = 0;

                for(auto dir : dirs){
                    int ni = i+dir[0];
                    int nj = j+dir[1];

                    if(ni>=0 && ni<m && nj<n && nj>=0 && abs(board[ni][nj]) == 1)
                    live++;
                }
                if(board[i][j] == 1 && live<2 || live>3)
                    board[i][j] == -1;
                if(board[i][j] == 0 && live == 3)
                    board[i][j] == 2;
            }
        }
        for(int i = 0; i<m; i++)
        for(int j = 0; j<n; j++)
        if (board[i][j] > 0)
        board[i][j] = 1;
        else
        board[i][j] = 0;
    }
};
