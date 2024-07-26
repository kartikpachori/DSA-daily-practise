class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Split the string into words
        vector<string> words;
        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Step 2: Reverse the list of words
        reverse(words.begin(), words.end());
        
        // Step 3: Join the reversed list of words with a single space
        string result;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) {
                result += " ";
            }
            result += words[i];
        }
        
        return result;
    }
};
