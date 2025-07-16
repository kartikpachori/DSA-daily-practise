class Solution {
  public:
    int floor(Node* root, int x) {
        int ans = -1;
        
        while (root) {
            if (root->data == x) {
                return root->data;
            } else if (root->data > x) {
                root = root->left;
            } else {
                ans = root->data;
                root = root->right;
            }
        }

        return ans;
    }
};
