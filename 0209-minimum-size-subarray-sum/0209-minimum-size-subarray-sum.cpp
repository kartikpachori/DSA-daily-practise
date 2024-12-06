class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0, sum = 0, minLength = INT_MAX;

        for (int end = 0; end < n; end++) {
            sum += nums[end];

            while (sum >= target) {
                minLength = min(minLength, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
