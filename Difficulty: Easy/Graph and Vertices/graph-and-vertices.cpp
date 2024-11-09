//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    long long count(int n) {
        int edges = (n * (n - 1)) / 2;
        return static_cast<long long>(pow(2, edges));
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.count(n) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends