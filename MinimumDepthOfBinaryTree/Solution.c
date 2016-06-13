/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    int l = -1;
    int r = -1;
    if (root->left != NULL) {
        l = minDepth(root->left);
    }
    if (root->right != NULL) {
        r = minDepth(root->right);
    }
    if (l == -1) return 1 + r;
    if (r == -1) return 1 + l;
    return 1 + (l < r ? l : r);
}
