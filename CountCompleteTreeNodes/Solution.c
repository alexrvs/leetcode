/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    int lh = 0;
    int rh = 0;
    struct TreeNode* node = root;
    while (node != NULL) { lh++; node = node->left; }
    node = root;
    while (node != NULL) { rh++; node = node->right; }
    if (lh == rh) { return pow(2, lh) - 1; }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
