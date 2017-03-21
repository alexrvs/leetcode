/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int helper(struct TreeNode* node, int* maxDiameter) {
    if (node == NULL) return 0;
    int l = helper(node->left, maxDiameter);
    int r = helper(node->right, maxDiameter);
    int diameter = l + r;
    if (*maxDiameter < diameter) *maxDiameter = diameter;
    return (l > r ? l : r) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int maxDiameter = 0;
    helper(root, &maxDiameter);
    return maxDiameter;
}