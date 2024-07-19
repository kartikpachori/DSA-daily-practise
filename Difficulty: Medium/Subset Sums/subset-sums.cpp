//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void func(int idx,int sum,vector<int> &arr,int N,vector<int> &ans){
        if(idx==N){
            ans.push_back(sum);
            return;
        }
        
        func(idx+1,sum+arr[idx],arr,N,ans);
        
        func(idx+1,sum,arr,N,ans);
    }
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int>ans;
        func(0,0,arr,n,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
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
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends