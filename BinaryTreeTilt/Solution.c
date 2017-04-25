/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int helper(struct TreeNode* node, int* tilt) {
    if (NULL == node) return 0;
    int l = helper(node->left, tilt);
    int r = helper(node->right, tilt);
    *tilt += abs(l - r);
    return l + r + node->val;
}
    
int findTilt(struct TreeNode* root) {
    int tilt = 0;
    helper(root, &tilt);
    return tilt;
}