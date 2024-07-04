//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int perfectSum(int arr[], int n, int sum) {
        const int MOD = 1000000007;
        // Create a DP array with (sum + 1) elements, initialized to 0
        vector<int> dp(sum + 1, 0);

        // Base case: there is one way to achieve sum 0 with 0 elements
        dp[0] = 1;

        // Fill the DP array
        for (int i = 0; i < n; ++i) {
            for (int j = sum; j >= arr[i]; --j) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
            }
        }

        // The answer is the number of ways to achieve the sum with all n elements
        return dp[sum];
    }
};






//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends