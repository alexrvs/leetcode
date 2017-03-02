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
private:
    void helper(TreeNode* node, int* prev, int* diff) {
        if (node == NULL) return;
        helper(node->left, prev, diff);
        if (*prev >= 0) {
            int curDiff = node->val - *prev;
            if (*diff > curDiff) {
                *diff = curDiff;
            }
        }
        *prev = node->val;
        helper(node->right, prev, diff);
        return;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
        TreeNode* node = root;
        while(node->right != NULL) node = node->right;
        int prev = -1;
        int diff = node->val;
        helper(root, &prev, &diff);
        return diff;
    }
};