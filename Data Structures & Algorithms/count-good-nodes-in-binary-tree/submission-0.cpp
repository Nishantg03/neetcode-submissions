class Solution {
public:
    void ans(int& ct, int maxi, TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        // Left
        if (root->left != nullptr) {

            if (root->left->val >= maxi) {
                ct++;
            }

            int newm = max(maxi, root->left->val);

            ans(ct, newm, root->left);
        }

        // Right
        if (root->right != nullptr) {

            if (root->right->val >= maxi) {
                ct++;
            }

            int newm = max(maxi, root->right->val);

            ans(ct, newm, root->right);
        }
    }

    int goodNodes(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int ct = 1;              // root is always good
        int maxi = root->val;

        ans(ct, maxi, root);

        return ct;
    }
};