class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both trees are empty
        if(p == nullptr && q == nullptr) {
            return true;
        }

        // One is empty, other is not
        if(p == nullptr || q == nullptr) {
            return false;
        }

        // Current node values are different
        if(p->val != q->val) {
            return false;
        }

        // Compare left subtrees
        bool left = isSameTree(p->left, q->left);

        // Compare right subtrees
        bool right = isSameTree(p->right, q->right);

        // Both must be same
        return left && right;
    }
};
