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
    int diameterOfBinaryTree(TreeNode* root) {
       int maxi =0;
       func(root,maxi);
        
    return maxi;
    }
    
private:
    int func(TreeNode* root,int& maxi){
        if(root == nullptr) return 0;
        
        int lh = func(root->left,maxi);
        int rh = func(root->right,maxi);
        
        maxi = max(maxi , rh+ lh);
        
        return 1 + max(rh,lh);
        
    }
};