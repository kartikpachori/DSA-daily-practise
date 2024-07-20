class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;  // This will store all the valid combinations
        vector<int> combination;     // This will store the current combination we are building
        findCombinations(result, combination, k, n, 1);
        return result;
    }
    
private:
    void findCombinations(vector<vector<int>>& result, vector<int>& combination, int k, int n, int start) {
        // Base case: if we have the desired number of elements in the combination and the sum is n
        if (combination.size() == k && n == 0) {
            result.push_back(combination);  // Add the current combination to the result
            return;
        }
        
        // Iterate through the numbers from 'start' to 9
        for (int i = start; i <= 9; ++i) {
            if (i > n) break;  // If the current number exceeds the remaining sum, no point in continuing
            
            combination.push_back(i);  // Add the current number to the combination
            // Recur with reduced n and increased start value to avoid using the same number again
            findCombinations(result, combination, k, n - i, i + 1);
            combination.pop_back();  // Backtrack: remove the current number from the combination
        }
    }
};
