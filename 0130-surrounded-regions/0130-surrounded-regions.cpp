class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        
        int n = board[0].size();
        auto bfs = [&](int i, int j) {
            queue<pair<int, int>> q;
            q.push({i, j});
            board[i][j] = 'S';
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O') {
                        board[nx][ny] = 'S';
                        q.push({nx, ny});
                    }
                }
            }
        };
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') bfs(i, 0);
            if (board[i][n - 1] == 'O') bfs(i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') bfs(0, j);
            if (board[m - 1][j] == 'O') bfs(m - 1, j);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
