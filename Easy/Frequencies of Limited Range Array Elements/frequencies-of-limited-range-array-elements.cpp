//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{
    public:
     // Function to count the frequency of all elements from 1 to N in the array.
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P) {
        // Step 1: Reduce numbers greater than N to zero as they are not within our interest range
        for (int i = 0; i < N; ++i) {
            if (arr[i] > N) {
                arr[i] = 0;
            }
        }
        
        // Step 2: Use the array to count frequencies of each element in the range [1, N]
        for (int i = 0; i < N; ++i) {
            int element = arr[i] % (N + 1); // Use modulo to get the original value if it was changed
            if (element > 0) {
                arr[element - 1] += (N + 1); // Increase the count by adding (N + 1)
            }
        }
        
        // Step 3: Extract the counts from the encoded values
        for (int i = 0; i < N; ++i) {
            arr[i] = arr[i] / (N + 1);
        }
    }
        
        // int hash[100000] ={0};
        // for(int i=1;i<N;i++){
        //     hash[arr[i]] +=1;
        // }
        // for(int j=1;j<P+1;j++){
        //     cout<<hash[j]<<" ";
        // }
    
};


//{ Driver Code Starts.

int main() 
{ 
	long long t;
	
	//testcases
	cin >> t;
	
	while(t--){
	    
	    int N, P;
	    //size of array
	    cin >> N; 
	    
	    vector<int> arr(N);
	    
	    //adding elements to the vector
	    for(int i = 0; i < N ; i++){
	        cin >> arr[i]; 
	    }
        cin >> P;
        Solution ob;
        //calling frequncycount() function
		ob.frequencyCount(arr, N, P); 
		
		//printing array elements
	    for (int i = 0; i < N ; i++) 
			cout << arr[i] << " ";
	    cout << endl;
	}	
	return 0; 
}





// } Driver Code Ends