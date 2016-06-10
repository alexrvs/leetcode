/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void helper(struct TreeNode* node, int * with, int * without) {
    int lw = 0;
    int lwo = 0;
    int rw = 0;
    int rwo = 0;
    int womax = 0;
    if (node == NULL) {
        *with = 0;
        *without = 0;
        return;
    }
    helper(node->left, &lw, &lwo);
    helper(node->right, &rw, &rwo);
    *with = node->val + lwo + rwo;
    if (womax < lw + rw) womax = lw + rw;
    if (womax < lwo + rw) womax = lwo + rw;
    if (womax < lw + rwo) womax = lw + rwo;
    if (womax < lwo + rwo) womax = lwo + rwo;
    *without = womax;
    return;
}

int rob(struct TreeNode* root) {
    int w = 0;
    int wo = 0;
    helper(root, &w, &wo);
    return w > wo ? w : wo;
}
