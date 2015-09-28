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
    void helper(TreeNode* node, vector<int>& vals) {
        if (node == NULL) return;
        helper(node->left, vals);
        helper(node->right, vals);
        vals.push_back(node->val);
        return;
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vals;
        helper(root, vals);
        return vals;
    }
};
