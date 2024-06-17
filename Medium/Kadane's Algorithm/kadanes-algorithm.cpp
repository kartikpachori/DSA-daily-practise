//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    long long int maxSubarraySum(int* nums, int n) {
        long long int sum = 0;
        long long int maxi = LLONG_MIN; // Use LLONG_MIN for long long int

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            maxi = std::max(maxi, sum);

            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends