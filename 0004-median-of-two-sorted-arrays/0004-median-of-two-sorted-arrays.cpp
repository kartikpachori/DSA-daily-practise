class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;
        
        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (n1 + n2 + 1) / 2 - partition1;
            
            // Edge cases for max and min
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 = (partition1 == n1) ? INT_MAX : nums1[partition1];
            
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 = (partition2 == n2) ? INT_MAX : nums2[partition2];
            
            // Check if partition is correct
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total number of elements is odd
                if ((n1 + n2) % 2 == 1) {
                    return std::max(maxLeft1, maxLeft2);
                } 
                // If total number of elements is even
                else {
                    return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
                }
            } 
            // Move left
            else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            } 
            // Move right
            else {
                low = partition1 + 1;
            }
        }
        
        throw std::invalid_argument("Input arrays are not sorted.");
    }
};
