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
    bool helper(vector<vector<int> > &res, vector<int> path, TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left == NULL && root->right == NULL) {
            path.push_back(root->val);
            res.push_back(path);
        } else {
            path.push_back(root->val);
            helper(res, path, root->left, sum - root->val);
            helper(res, path, root->right, sum - root->val);
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        helper(res, path, root, sum);
        return res;
    }
};
