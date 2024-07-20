class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  // If the input is empty, return an empty vector

        // Mapping of digits to corresponding letters
        vector<string> digitToLetters = {
            "",    // 0
            "",    // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs",// 7
            "tuv", // 8
            "wxyz" // 9
        };
        
        vector<string> result;  // This will store the result
        string currentCombination;  // This will store the current combination being built
        backtrack(result, digitToLetters, digits, currentCombination, 0);
        return result;
    }
    
public:
    void backtrack(vector<string>& result, const vector<string>& digitToLetters, const string& digits, string& currentCombination, int index) {
        if (index == digits.size()) {  // If we've reached the end of the digits string
            result.push_back(currentCombination);  // Add the current combination to the result
            return;
        }
        
        // Get the letters that the current digit maps to, and loop through them
        string letters = digitToLetters[digits[index] - '0'];
        for (char letter : letters) {
            currentCombination.push_back(letter);  // Add the letter to the current combination
            backtrack(result, digitToLetters, digits, currentCombination, index + 1);  // Recur for the next digit
            currentCombination.pop_back();  // Backtrack: remove the letter before moving to the next one
        }
    }
};
