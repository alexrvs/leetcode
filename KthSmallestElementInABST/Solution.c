/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int helper(struct TreeNode* node, int n, int k, int* res) {
    if (n >= k || node == NULL) return n;
    n = helper(node->left, n, k, res);
    if (++n == k) { *res = node->val; }
    return helper(node->right, n, k, res);
}

int kthSmallest(struct TreeNode* root, int k) {
    int res = 0;
    helper(root, 0, k, &res);
    return res;
}
