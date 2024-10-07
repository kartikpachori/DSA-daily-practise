class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if (totalSum % 2 != 0) {
            return false;
        }
        
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; 
        
        for (int num : nums) {
            for (int i = target; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        
        return dp[target];
    }
};
