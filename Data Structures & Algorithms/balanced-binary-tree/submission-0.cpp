class Solution {
public:

    int height(TreeNode* root) {

        // Empty tree is balanced and has height 0
        if(root == nullptr) {
            return 0;
        }

        // Get left height
        int left = height(root->left);

        // If left subtree is unbalanced
        if(left == -1) {
            return -1;
        }

        // Get right height
        int right = height(root->right);

        // If right subtree is unbalanced
        if(right == -1) {
            return -1;
        }

        // Current node is unbalanced
        if(abs(left - right) > 1) {
            return -1;
        }

        // Return height to parent
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
