class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(nums, 0, current, result);
        return result;
    }
    
private:
    void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
        // If index equals nums.size(), add current to result and return
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }
        
        // Include the current element first
        current.push_back(nums[index]);
        generateSubsets(nums, index + 1, current, result);
        current.pop_back();
        
        // Then recur without including the current element
        generateSubsets(nums, index + 1, current, result);
    }
};
