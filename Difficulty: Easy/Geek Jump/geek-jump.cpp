//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mini(int idx,vector<int>& heights,vector<int>&dp){
        if (idx==0)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int left = mini(idx-1,heights,dp) + abs(heights[idx]-heights[idx-1]);
        int right = INT_MAX;
        if (idx>1) right = mini(idx-2,heights,dp) + abs(heights[idx-2]-heights[idx]);
        
        return dp[idx]=min(left,right);
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
       return mini(n-1,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends