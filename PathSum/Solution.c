/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if (root == NULL) return false;
    if (root->val == sum && root->left == NULL && root->right == NULL) return true;
    bool left = hasPathSum(root->left, sum - root->val);
    bool right = hasPathSum(root->right, sum - root->val);
    return (left || right);
}
