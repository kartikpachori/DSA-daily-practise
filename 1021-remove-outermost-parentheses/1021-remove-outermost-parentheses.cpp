class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int balance = 0;
        
        // Loop through each character in the string
        for (char c : s) {
            // When encountering an opening parenthesis
            if (c == '(') {
                // If balance is already greater than 0, add to result
                if (balance > 0) {
                    result += c;
                }
                // Increment balance
                balance++;
            } 
            // When encountering a closing parenthesis
            else {
                // Decrement balance
                balance--;
                // If balance is still greater than 0 after decrement, add to result
                if (balance > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};
