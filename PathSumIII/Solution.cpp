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
    int helper(TreeNode* root, vector<int> &sums, int target) {
        int cnt = 0;
        if (root == NULL) return cnt;
        for (int i = 0; i < sums.size(); i++) {
            sums[i] += root->val;
            if (sums[i] == target) cnt++;
        }
        if (root->val == target) cnt++;
        sums.push_back(root->val);
        cnt += helper(root->left, sums, target);
        cnt += helper(root->right, sums, target);
        sums.pop_back();
        for (int i = 0; i < sums.size(); i++) {
            sums[i] -= root->val;
        }
        return cnt;
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        vector<int> sums;
        return helper(root, sums, sum);
    }
};