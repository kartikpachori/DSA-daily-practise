//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void printmos(int i , int N){
      if (i<1){
          return ; 
      }
      cout<<i<<" ";
      printmos(i-1, N);
  }
    void printNos(int N) {
       return printmos( N , N);
    }
};

//{ Driver Code Starts.
/* Driver program to test printNos */
int main() {
    int T;

    // taking testcases
    cin >> T;

    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printNos(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends