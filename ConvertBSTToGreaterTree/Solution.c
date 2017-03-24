/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void helper(struct TreeNode* node, int* sum) {
    if (node == NULL) return;
    helper(node->right, sum);
    *sum += node->val;
    node->val = *sum;
    helper(node->left, sum);
    return;
}

struct TreeNode* convertBST(struct TreeNode* root) {
    int sum = 0;
    helper(root, &sum);
    return root;
}