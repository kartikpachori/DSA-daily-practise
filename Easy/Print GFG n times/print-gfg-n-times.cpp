//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void Printgf(int i,int N){
      if(i>N){
          return ;
      }
      cout<<"GFG"<<" ";
      Printgf(i+1,N);
  }
    void printGfg(int N) {
        Printgf(1,N);
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
        ob.printGfg(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends