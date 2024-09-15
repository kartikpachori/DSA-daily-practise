

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--;  // Adjust for 1-based indexing
            char ch = 'A' + (columnNumber % 26);  // Map to the correct character
            result = ch + result;  // Append character to result
            columnNumber /= 26;  // Move to the next digit
        }
        return result;
    }
};
