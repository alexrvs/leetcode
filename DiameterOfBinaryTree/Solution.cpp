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
    int maxDiameter;
    int helper(TreeNode* node) {
        if (node == NULL) return 0;
        int l = helper(node->left);
        int r = helper(node->right);
        if (maxDiameter < l + r) maxDiameter = l + r;
        return (l > r ? l : r) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        helper(root);
        return maxDiameter;
    }
};