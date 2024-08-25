#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> brackets = {{')', '('}, {'}', '{'}, {']', '['}};
        
        for (char c : s) {
            // If it's a closing bracket
            if (brackets.count(c)) {
                // Check if stack is not empty and the top matches the corresponding opening bracket
                if (!st.empty() && st.top() == brackets[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                // It's an opening bracket, push it onto the stack
                st.push(c);
            }
        }
        
        // The string is valid if the stack is empty
        return st.empty();
    }
};
