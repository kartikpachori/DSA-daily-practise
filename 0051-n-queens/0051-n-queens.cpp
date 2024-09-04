class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.')); // Initialize the board with empty cells
        solve(0, n, board, results);  // Start solving from the 0th row
        return results;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& results) {
        if (row == n) { // All queens are placed successfully
            results.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q'; // Place the queen
                solve(row + 1, n, board, results); // Recurse for the next row
                board[row][col] = '.'; // Backtrack and remove the queen
            }
        }
    }

    bool isSafe(int row, int col, int n, vector<string>& board) {
        // Check the column for any other queens
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;

        // Check the top-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // Check the top-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }
};
