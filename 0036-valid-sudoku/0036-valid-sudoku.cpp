class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9), col(9), box(9);
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char current = board[r][c];
                if (current == '.') continue;

                int boxIndex = (r / 3) * 3 + (c / 3);
                if (row[r].count(current) || col[c].count(current) || box[boxIndex].count(current)) {
                    return false;
                }
                row[r].insert(current);
                col[c].insert(current);
                box[boxIndex].insert(current);
            }
        }
        return true;
    }
};
