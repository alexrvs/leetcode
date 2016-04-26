/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode* l, struct TreeNode* r) {
    if (l == NULL && r == NULL) return true;
    if (l == NULL || r == NULL) return false;
    if (l->val != r->val) return false;
    return helper(l->left, r->right) && helper(l->right, r->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;
    return helper(root->left, root->right);
}
