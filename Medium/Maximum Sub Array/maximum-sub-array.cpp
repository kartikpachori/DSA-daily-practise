//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution {
public:
    vector<int> findSubarray(int a[], int n) {
        long long maxSum = -1, currentSum = 0;
        vector<int> result, temp;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] >= 0) {
                currentSum += a[i];
                temp.push_back(a[i]);
            } else {
                if (currentSum > maxSum || 
                    (currentSum == maxSum && temp.size() > result.size())) {
                    maxSum = currentSum;
                    result = temp;
                }
                currentSum = 0;
                temp.clear();
            }
        }
        
        // Final check for the last subarray
        if (currentSum > maxSum || 
            (currentSum == maxSum && temp.size() > result.size())) {
            result = temp;
        }
        
        return result.empty() ? vector<int>{-1} : result;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends