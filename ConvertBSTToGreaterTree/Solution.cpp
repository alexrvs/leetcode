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
    void helper(TreeNode* node, int* sum) {
        if (node == NULL) return;
        helper(node->right, sum);
        *sum += node->val;
        node->val = *sum;
        helper(node->left, sum);
        return;
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        helper(root, &sum);
        return root;
    }
};