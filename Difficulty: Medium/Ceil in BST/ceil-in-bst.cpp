/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    int ans = -1;

    while (root) {
        if (root->data == input) {
            return root->data;
        } else if (root->data < input) {
            root = root->right;
        } else {
            ans = root->data;
            root = root->left;
        }
    }

    return ans;
}
