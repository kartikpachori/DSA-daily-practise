class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) ;  // Use the value as the index (adjusted for 1-based index)
            if (nums[index] < 0) {
                return abs(nums[i]);  // Duplicate found
            }
            nums[index] = -nums[index];  // Mark as visited by making it negative
        }
        
        return -1;  // Should never reach here, as there is always a duplicate
    }
};
