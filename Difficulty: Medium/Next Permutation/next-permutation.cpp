//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> nextPermutation(int N, vector<int> arr) {
        int idx = -1;

        // Step 1: Find the first decreasing element from the end
        for (int i = N - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1]) {
                idx = i;
                break;
            }
        }

        // Step 2: If no such element is found, reverse the whole array
        if (idx == -1) {
            reverse(arr.begin(), arr.end());
            return arr;
        }

        // Step 3: Find the smallest element greater than arr[idx] to the right
        for (int i = N - 1; i > idx; i--) {
            if (arr[i] > arr[idx]) {
                swap(arr[i], arr[idx]);
                break;
            }
        }

        // Step 4: Reverse the elements to the right of idx to get the next permutation
        reverse(arr.begin() + idx + 1, arr.end());

        return arr;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends