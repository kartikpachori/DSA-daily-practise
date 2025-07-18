class Solution {
  public:
    int func(int idx,int W,vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
        
        //base case
        if(idx==val.size()-1){
            if(wt[idx]<=W) return val[idx];
            return 0;
        }
        
        //logic
        if(dp[idx][W] != -1) return dp[idx][W];
        
        int not_take = func(idx+1,W,val,wt,dp);
        int take = 0;
        if(wt[idx]<=W){
            take = val[idx] + func(idx+1,W-wt[idx],val,wt,dp);
        }
        
        //return
        return dp[idx][W] = max(not_take,take);
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return func(0,W,val,wt,dp);
    }
};