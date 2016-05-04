/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int count(struct TreeNode* node) {
    if (node == NULL) return 0;
    return 1 + count(node->left) + count(node->right);
}

void helper(struct TreeNode* node, int* vals, int* index) {
    if (node == NULL) return;
    helper(node->left, vals, index);
    helper(node->right, vals, index);
    vals[(*index)] = node->val;
    (*index)++;
    return;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = count(root);
    int* vals = (int*) malloc((*returnSize) * sizeof(int));
    int index = 0;
    helper(root, vals, &index);
    return vals;
}
