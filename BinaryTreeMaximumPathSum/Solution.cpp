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
    int max;
    void findMin(TreeNode* node) {
        if (node == NULL) return;
        if (node->val < max) max = node->val;
        findMin(node->left);
        findMin(node->right);
    }
    int helper(TreeNode* node) {
        if (node == NULL) return 0;
        int leftSum = helper(node->left);
        int rightSum = helper(node->right);
        int curSum = node->val;
        if (leftSum > 0) curSum += leftSum;
        if (rightSum > 0) curSum += rightSum;
        if (curSum > max) {
            max = curSum;
        }
        curSum = node->val;
        if (leftSum > rightSum) {
            if (leftSum > 0) curSum += leftSum;
        } else {
            if (rightSum > 0) curSum += rightSum;
        }
        return curSum;
    }
public:
    int maxPathSum(TreeNode* root) {
        max = 0;
        findMin(root);
        helper(root);
        return max;
    }
};
