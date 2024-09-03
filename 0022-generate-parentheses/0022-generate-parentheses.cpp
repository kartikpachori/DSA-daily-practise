#include <vector>
#include <string>

class Solution {
public:
    void backtrack(int n, int open, int close, std::string current, std::vector<std::string>& result) {
        // If the current string has reached the maximum length (2 * n), add it to the result
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        
        // If we can add an open parenthesis, do it and continue the recursion
        if (open < n) {
            backtrack(n, open + 1, close, current + '(', result);
        }
        
        // If we can add a close parenthesis, do it and continue the recursion
        if (close < open) {
            backtrack(n, open, close + 1, current + ')', result);
        }
    }
    
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        backtrack(n, 0, 0, "", result); // Start the backtracking process
        return result;
    }
};
