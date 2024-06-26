class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();

        // Step 1: Find the first decreasing element from the end
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // Step 2: If no such element is found, reverse the whole array
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the smallest element greater than nums[idx] to the right
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // Step 4: Reverse the elements to the right of idx to get the next permutation
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
