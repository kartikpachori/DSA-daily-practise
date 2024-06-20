//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends


class Solution {
public:
    long long pairWithMaxSum(long long arr[], long long N) {
        if (N < 2) return 0;  // Not enough elements for any valid subarray.
        
        long long maxSum = LLONG_MIN; // Initialize to a very small value.
        
        for (long long i = 0; i < N - 1; i++) {
            // Calculate the sum of the current pair
            long long currentSum = arr[i] + arr[i + 1];
            
            // Update maxSum if we find a new maximum
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
        
        return maxSum;
    }
};



//{ Driver Code Starts.
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}


// } Driver Code Ends