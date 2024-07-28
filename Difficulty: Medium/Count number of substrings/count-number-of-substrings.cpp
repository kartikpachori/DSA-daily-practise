//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    long long int substrCount (string s, int k) {
        return countSubstringsWithAtMostKDistinct(s, k) - countSubstringsWithAtMostKDistinct(s, k - 1);
    }

private:
    long long int countSubstringsWithAtMostKDistinct(const string& s, int k) {
        if (k == 0) return 0;
        
        vector<int> freq(26, 0); // frequency of each character (since input is lowercase English letters)
        int left = 0, right = 0;
        int distinctCount = 0;
        long long int result = 0;
        
        while (right < s.size()) {
            if (freq[s[right] - 'a'] == 0) {
                distinctCount++;
            }
            freq[s[right] - 'a']++;
            right++;
            
            while (distinctCount > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) {
                    distinctCount--;
                }
                left++;
            }
            
            result += right - left; // all substrings ending at 'right - 1' and starting from 'left' to 'right - 1'
        }
        
        return result;
    }
};




//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends