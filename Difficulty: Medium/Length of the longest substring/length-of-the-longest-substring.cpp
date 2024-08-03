//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    int longestUniqueSubsttr(string S) {
        // Array to store the last index of every character in the string
        int lastIndex[26];
        fill(lastIndex, lastIndex + 26, -1); 
        
        int n = S.size();
        int l = 0, maxlen = 0;
        
        for (int r = 0; r < n; ++r) {
            // Map character 'a' to 0, 'b' to 1, ..., 'z' to 25
            int index = S[r] - 'a';
            
            if (lastIndex[index] != -1 && lastIndex[index] >= l) {
                // Move the left pointer to the right of the last occurrence of S[r]
                l = lastIndex[index] + 1;
            }
            
            // Calculate the current length of the substring
            int len = r - l + 1;
            maxlen = max(maxlen, len);
            
            // Update the last occurrence of the current character
            lastIndex[index] = r;
        }
        
        return maxlen;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends