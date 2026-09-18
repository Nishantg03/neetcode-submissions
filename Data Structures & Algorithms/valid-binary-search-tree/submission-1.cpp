class Solution {
public:

    bool check(TreeNode* root, long long low, long long high) {

        if (root == nullptr) {
            return true;
        }

        // Current node must be inside the allowed range
        if (root->val <= low || root->val >= high) {
            return false;
        }

        // Left subtree: values must be smaller than root
        if (!check(root->left, low, root->val)) {
            return false;
        }

        // Right subtree: values must be greater than root
        if (!check(root->right, root->val, high)) {
            return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};