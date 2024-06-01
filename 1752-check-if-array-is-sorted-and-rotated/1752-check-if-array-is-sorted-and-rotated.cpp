class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();  // Get the size of the array
        int count = 0;  // Initialize a counter for decreasing points

        // Loop through the array to find decreasing points
        for (int i = 0; i < n; i++) {
            // Compare current element with the next element (modulo n for wrap-around)
            if (nums[i] > nums[(i + 1) %n]) {
                count++;  // Increment the count if a decreasing point is found
            }
        }

        // Return true if the count is less than or equal to 1, otherwise false
        return count <= 1;
    }
};