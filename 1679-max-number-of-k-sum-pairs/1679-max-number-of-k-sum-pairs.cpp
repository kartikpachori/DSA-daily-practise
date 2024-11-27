class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int operations = 0;

        for (int num : nums) {
            int complement = k - num;
            if (count[complement] > 0) {
                operations++;
                count[complement]--; 
            } else {
                count[num]++; 
            }
        }
        return operations;
    }
};
