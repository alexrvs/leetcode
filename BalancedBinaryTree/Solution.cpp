/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* node, int* height) {
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

    bool isBalanced(TreeNode* root) {
        int h;
        return helper(root, &h);
    }
};
