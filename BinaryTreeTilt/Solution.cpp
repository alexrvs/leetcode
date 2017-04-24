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
    int tilt;
    
    int helper(TreeNode* node) {
        if (NULL == node) return 0;
        int l = helper(node->left);
        int r = helper(node->right);
        tilt += abs(l - r);
        return l + r + node->val;
    }
    
public:
    int findTilt(TreeNode* root) {
        tilt = 0;
        helper(root);
        return tilt;
    }
};