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
    vector<int> vals;

    void helper(TreeNode* node) {
        if (node == NULL) return;
        helper(node->left);
        vals.push_back(node->val);
        helper(node->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        helper(root);
        for (int i = 1; i < vals.size(); i++) {
            if (vals[i] <= vals[i - 1]) return false;
        }
        return true;
    }
};
