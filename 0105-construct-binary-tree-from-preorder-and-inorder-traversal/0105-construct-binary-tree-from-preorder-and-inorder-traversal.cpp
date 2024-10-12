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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        return buildSubtree(preorder, inorder, inorderMap, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    
private:
    TreeNode* buildSubtree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorderMap, int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        int rootIndex = inorderMap[rootVal];
        int leftSize = rootIndex - inStart;
        root->left = buildSubtree(preorder, inorder, inorderMap, preStart + 1, preStart + leftSize, inStart, rootIndex - 1);
        root->right = buildSubtree(preorder, inorder, inorderMap, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd);
                return root;
    }
};
