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
    void flatten(TreeNode* root) {
        TreeNode* current = root;
        
        while (current != nullptr) {
            if (current->left != nullptr) {
                TreeNode* rightmost = current->left;
                while (rightmost->right != nullptr) {
                    rightmost = rightmost->right;
                }
                rightmost->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }
            current = current->right;
        }
    }
};
