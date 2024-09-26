class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        if (n<=2){
            return n;
        }
        return climbstairshelp(n,dp);
    }
 private: 
    int climbstairshelp(int n , vector<int>&dp){
        if(n<=2)
          return n;
        
       if(dp[n]!=-1) return dp[n];
        
       dp[n] = climbstairshelp(n-1,dp)+ climbstairshelp(n-2,dp);
          return dp[n];
    }
};

