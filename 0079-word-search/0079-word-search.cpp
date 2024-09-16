class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // Check if we have found the entire word
        if (index == word.size()) {
            return true;
        }

        // Check boundary conditions and if the current character matches
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        // Mark the current cell as visited by temporarily changing the character
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 possible directions: up, down, left, right
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);

        // Backtrack by restoring the original character
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // Iterate through the entire grid to find the starting point for DFS
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
