//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
   
    int majorityElement(int a[], int size)
    {
        
       
        int el;
        int count=0;
        
        for(int i=0;i<size;i++){
            if(count ==0){
                count= 1;
                el =a[i];
            }
            else if(a[i]==el){
                count++;
            }
            else{
                count--;
            }
        }
       int count1=0;
       for(int j=0;j<size;j++){
           if(a[j]==el){
               count1++;
           }
       }
       if(count1>size/2){
           return el;
       }
       else{
           return -1;
       }
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends