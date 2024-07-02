class Solution {
public:
    bool isPalindrome(string s) {
    string filteredStr = "";
    
    // Normalize the string: convert to lowercase and filter non-alphanumeric characters
    for (char c : s) {
        if (isalnum(c)) { // Check if the character is alphanumeric
            filteredStr += tolower(c); // Convert to lowercase and add to filteredStr
        }
    }
    
    // Check if filteredStr is a palindrome
    int n = filteredStr.size();
    for (int i = 0; i < n / 2; ++i) {
        if (filteredStr[i] != filteredStr[n - i - 1]) {
            return false; // Not a palindrome
        }
    }
    
    return true; // It is a palindrome
}
};