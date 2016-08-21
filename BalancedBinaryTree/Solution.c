/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode* node, int* height) {
    if (node == NULL) {
        *height = 0;
        return true;
    }
    if (node->left == NULL && node->right == NULL) {
        *height = 1;
        return true;
    }
    int left_h, right_h, diff;
    if (helper(node->left, &left_h) && helper(node->right, &right_h)) {
        diff = left_h > right_h ? left_h - right_h : right_h - left_h;
        if (diff <= 1) {
            *height = 1 + (left_h > right_h ? left_h : right_h);
            return true;
        }
    }
    return false;
}

bool isBalanced(struct TreeNode* root) {
    int h;
    return helper(root, &h);
}
