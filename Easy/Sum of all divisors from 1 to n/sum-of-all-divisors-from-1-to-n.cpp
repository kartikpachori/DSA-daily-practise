//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    // {
    //     long long sum =0;
    //     int i,j;
    //     for(i=1;i<N+1;i++){
    //       for(j=1;j<i+1;j++) {
    //           if(i%j==0){
    //               sum = sum + j;
    //           } 
    //       }
    //     }
    //     return sum;
    // }
    {
    long long sum = 0;

    // Iterate over each potential divisor
    for (int j = 1; j <= N; ++j) {
        // Add j to the sum for each multiple of j up to N
        sum += j * (N / j);
    }

    return sum;
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends