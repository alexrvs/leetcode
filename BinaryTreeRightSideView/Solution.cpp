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
    vector<int> m_view;
    void helper(TreeNode* node, int layer) {
        if (node == NULL) return;
        if (layer > m_view.size()) m_view.push_back(node->val);
        helper(node->right, layer + 1);
        helper(node->left, layer + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        m_view.clear();
        helper(root, 1);
        return m_view;
    }
};
