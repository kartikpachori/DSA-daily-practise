//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    const int MOD = 1e9 + 7; // Define the modulo constant

    long long int func(int n, vector<long long int>& dp) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        
        // Correct function call with modulo operation
        return dp[n] = (func(n-1, dp) + func(n-2, dp)) % MOD;
    }
    
    long long int topDown(int n) {
        vector<long long int> dp(n + 1, -1);
        return func(n, dp);
    }
    
    long long int bottomUp(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        long long int prev2 = 0;
        long long int prev = 1;
        
        for (long long int i = 2; i <= n; ++i) {
            long long int curr = (prev2 + prev) % MOD;
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends