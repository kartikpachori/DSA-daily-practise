/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        func(root, maxi);
        return maxi;
    }

private:
    int func(TreeNode* root, int& maxi) {
        if (root == nullptr) return 0;
        
        // Compute the maximum path sum for left and right subtrees
        int lh = max(0, func(root->left, maxi));  // Ignore negative paths
        int rh = max(0, func(root->right, maxi)); // Ignore negative paths
        
        // Update the overall maximum path sum with the current root value
        maxi = max(maxi, rh + lh + root->val);
        
        // Return the maximum path sum including the current root
        return root->val + max(lh, rh);
    }
};
