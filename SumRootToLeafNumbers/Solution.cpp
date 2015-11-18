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
    int sum;
    void helper(TreeNode* node, int prefix) {
        if (node == NULL) return;
        int curVal = prefix * 10 + node->val;
        if (node->left == NULL && node->right == NULL) {
            sum += curVal;
        }
        helper(node->left, curVal);
        helper(node->right, curVal);
        return;
    }

public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        helper(root, 0);
        return sum;
    }
};
