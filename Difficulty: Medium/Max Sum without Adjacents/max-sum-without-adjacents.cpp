// User function template for C++
class Solution {
 private:
  int solve(int index, vector<int>& arr, vector<int>& dp) {
    if (index < 0) {
      return 0;
    }
    if (index == 0) {
      return arr[0];
    }
    if (dp[index] != -1) {
      return dp[index];
    }

    int include = arr[index] + solve(index - 2, arr, dp);
    int exclude = solve(index - 1, arr, dp);

    return dp[index] = max(include, exclude);
  }

 public:
  int findMaxSum(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    vector<int> dp(n, -1);
    
    return solve(n - 1, arr, dp);
  }
};