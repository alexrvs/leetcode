/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void helper(struct TreeNode* node, int prefix, int* sum) {
    if (NULL == node) return;
    int curVal = prefix * 10 + node->val;
    if (node->left == NULL && node->right == NULL) {
        *sum += curVal;
    }
    helper(node->left, curVal, sum);
    helper(node->right, curVal, sum);
    return;
}
 
int sumNumbers(struct TreeNode* root) {
    int sum = 0;
    helper(root, 0, &sum);
    return sum;
}