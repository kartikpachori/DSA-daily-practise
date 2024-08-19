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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Place the node's value in the appropriate position in the level array
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;
                
                // Push the children of the current node into the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // After processing the level, flip the direction
            leftToRight = !leftToRight;
            result.push_back(level);
        }
        
        return result;
    }
};
