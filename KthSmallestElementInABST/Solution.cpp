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
    int m_res;
    int helper(TreeNode* node, int n, int k) {
        if (n >= k || node == NULL) return n;
        n = helper(node->left, n, k);
        if (++n == k) m_res = node->val;
        return helper(node->right, n, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root, 0, k);
        return m_res;
    }
};
