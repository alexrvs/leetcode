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
    void helper(vector<vector<int> >& res, TreeNode* node, int l) {
        if (node == NULL) return;
        int size = res.size();
        if (l >= size) {
            vector<int> level;
            res.push_back(level);
        }
        res[l].push_back(node->val);
        helper(res, node->left, l + 1);
        helper(res, node->right, l + 1);
        return;
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        helper(res, root, 0);
        return res;
    }
};
