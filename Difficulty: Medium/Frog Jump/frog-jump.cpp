class Solution {
  public:
    int f(int i, vector<int>& height, vector<int>& dp) {
        if (i == 0) return 0;
        if (dp[i] != -1) return dp[i];
        
        int left = f(i - 1, height, dp) + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = f(i - 2, height, dp) + abs(height[i] - height[i - 2]);
        
        return dp[i] = min(left, right);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return f(n - 1, height, dp);
    }
};
