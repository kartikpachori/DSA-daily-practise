//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  long long a;
    long long sum(long long n){
        if(n==0){
            return 0;
        }
        a = n*n*n + sum(n-1);
        return a;
    }
    long long sumOfSeries(long long n) {
      long long result = sum(n);
      return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends