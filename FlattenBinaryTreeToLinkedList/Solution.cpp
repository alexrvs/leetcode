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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left != NULL) {
            TreeNode* leftTail = root->left;
            while (leftTail->right != NULL) {
                leftTail = leftTail->right;
            }
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        return;
    }
};
