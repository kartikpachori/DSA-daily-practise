//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to reverse words in a given string.
    string reverseWords(string S) { 
        vector<string> words;
        string word;
        stringstream ss(S);

        // Split the string into words based on the delimiter '.'
        while (getline(ss, word, '.')) {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        // Join the words back into a single string separated by '.'
        string result;
        for (size_t i = 0; i < words.size(); ++i) {
            if (i != 0) {
                result += '.';
            }
            result += words[i];
        }

        return result;
    }
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends