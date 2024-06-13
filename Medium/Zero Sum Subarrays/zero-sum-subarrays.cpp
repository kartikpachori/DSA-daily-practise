//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    long long int findSubarray(vector<long long int> &arr, int n) {
        unordered_map<long long, int> prefixSumMap;
        long long currentSum = 0;
        long long count = 0;
        
        for (int i = 0; i < n; ++i) {
            currentSum += arr[i];
            
            if (currentSum == 0) {
                count++;
            }
            
            if (prefixSumMap.find(currentSum) != prefixSumMap.end()) {
                count += prefixSumMap[currentSum];
            }
            
            prefixSumMap[currentSum]++;
        }
        
        return count;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends