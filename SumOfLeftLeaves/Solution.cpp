/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 0;
        int l = 0;
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
            l = root->left->val;
        } else {
            l = sumOfLeftLeaves(root->left);
        }
        int r = sumOfLeftLeaves(root->right);
        return l + r;
    }
};
