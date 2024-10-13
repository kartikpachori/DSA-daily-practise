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
    void inOrder(TreeNode* node, int& count, int& result, int k) {
        if (!node || count >= k) return;
        inOrder(node->left, count, result, k);
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        inOrder(node->right, count, result, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0; 
        int result = 0;
        inOrder(root, count, result, k);  
        return result;  
    }
};

