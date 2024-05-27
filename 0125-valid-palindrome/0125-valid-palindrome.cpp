class Solution {
public:
    bool isPalindrome(std::string s) {
        // Step 1: Filter the string to include only alphanumeric characters and convert to lowercase
        std::string filtered;
        for (char c : s) {
            if (std::isalnum(c)) {
                filtered += std::tolower(c);
            }
        }
        
        // Step 2: Use a recursive function to check if the filtered string is a palindrome
        return isPalindromeRecursive(filtered, 0, filtered.size() - 1);
    }
    
private:
    bool isPalindromeRecursive(const std::string &s, int left, int right) {
        // Base case: if pointers have crossed each other, it is a palindrome
        if (left >= right) {
            return true;
        }
        
        // Check characters at current pointers
        if (s[left] != s[right]) {
            return false;
        }
        
        // Move towards the center
        return isPalindromeRecursive(s, left + 1, right - 1);
    }
};