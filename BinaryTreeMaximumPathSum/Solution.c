/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void findMin(struct TreeNode* node, int* min) {
    if (node == NULL) return;
    if (node->val < *min) {
        *min = node->val;
    }
    findMin(node->left, min);
    findMin(node->right, min);
    return;
}
 
int helper(struct TreeNode* node, int* max) {
    if (node == NULL) return 0;
    int curSum = node->val;
    int leftSum = helper(node->left, max);
    int rightSum = helper(node->right, max);
    if (leftSum > 0) curSum += leftSum;
    if (rightSum > 0) curSum += rightSum;
    if (curSum > *max) {
        *max = curSum;
    }
    curSum = node->val;
    if (leftSum > rightSum) {
        if (leftSum > 0) {
            curSum += leftSum;
        }
    } else {
        if (rightSum > 0) {
            curSum += rightSum;
        }
    }
    return curSum;
}
 
int maxPathSum(struct TreeNode* root) {
    int res = 0;
    findMin(root, &res);
    helper(root, &res);
    return res;
}