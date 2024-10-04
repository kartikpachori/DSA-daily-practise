class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();  
        vector<vector<int>> dp = matrix;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += dp[i - 1][j - 1];
                } else {
                    leftDiagonal += 1e9; 
                }
                int rightDiagonal = matrix[i][j];
                if (j + 1 < n) {
                    rightDiagonal += dp[i - 1][j + 1];
                } else {
                    rightDiagonal += 1e9;  
                }
                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[n - 1][j]);
        }

        return mini;
    }
};
