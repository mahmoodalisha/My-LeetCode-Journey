class Solution {
public:
    int m, n;
    vector<vector<char>> board;
    vector<vector<bool>> visited;

    // 4 directions: right, down, left, up
    vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    bool dfs(int x, int y, int fromX, int fromY, char target) {
        visited[x][y] = true;  // current cell ko visited mark karo

        for (auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;

            // 1. Bounds check
            if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;

            // 2. Same character check
            if (board[newX][newY] != target) continue;

            // 3. Don't go back to the immediate previous cell
            if (newX == fromX && newY == fromY) continue;

            // 4. If already visited → cycle found
            if (visited[newX][newY]) return true;

            // 5. DFS on neighbor
            if (dfs(newX, newY, x, y, target)) return true;
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        board = grid;
        visited.assign(m, vector<bool>(n, false));  // sab unvisited initially

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    // Start DFS from unvisited cell
                    if (dfs(i, j, -1, -1, board[i][j])) {
                        return true;  // cycle mil gaya
                    }
                }
            }
        }

        return false;  // koi cycle nahi mila
    }
};
/*
target wo character hai jiska cycle dhund rahe ho — matlab wo letter jisme same-same character ka cycle ban sakta hai.
*/