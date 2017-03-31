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
    int height(TreeNode* node) {
        if (NULL == node) return 0;
        int l = height(node->left);
        int r = height(node->right);
        return (l > r ? l : r) + 1;
    }
    
    int min(TreeNode* node) {
        int res = node->val;
        if (node->left) {
            int l = min(node->left);
            res = res > l ? l : res;
        }
        if (node->right) {
            int r = min(node->right);
            res = res > r ? r : res;
        }
        return res;
    }
    
    void helper(TreeNode* node, int l, vector<int>& res) {
        if (NULL == node) return;
        if (res[l] < node->val) res[l] = node->val;
        helper(node->left, l + 1, res);
        helper(node->right, l + 1, res);
        return;
    }
    
public:
    vector<int> largestValues(TreeNode* root) {
        if (NULL == root) return vector<int>();
        int h = height(root);
        int m = min(root);
        vector<int> res(h, m);
        helper(root, 0, res);
        return res;
    }
};