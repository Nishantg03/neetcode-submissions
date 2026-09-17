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

    int ans = 0;

    int height(TreeNode* root) {

        // Base case
        if(root == nullptr) {
            return 0;
        }

        // Calculate left and right height
        int left = height(root->left);
        int right = height(root->right);

        // Option 1: diameter passing through current node
        ans = max(ans, left + right);

        // Option 2: return the maximum height to parent
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return ans;
    }
};