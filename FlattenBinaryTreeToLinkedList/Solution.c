/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if (root == NULL) return;
    flatten(root->left);
    flatten(root->right);
    if (root->left != NULL) {
        struct TreeNode* leftTail = root->left;
        while (leftTail->right != NULL) {
            leftTail = leftTail->right;
        }
        leftTail->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    return;
}
