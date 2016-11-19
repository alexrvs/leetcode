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
    vector<TreeNode*> helper(vector<int>& nums, int start, int end) {
        vector<TreeNode*> nodes;
        if (start > end) {
            nodes.push_back(NULL);
            return nodes;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = helper(nums, start, i - 1);
            vector<TreeNode*> rightTrees = helper(nums, i + 1, end);
            for (int j = 0; j < leftTrees.size(); j++) {
                for (int k = 0; k < rightTrees.size(); k++) {
                    TreeNode* node = new TreeNode(nums[i]);
                    node->left = leftTrees[j];
                    node->right = rightTrees[k];
                    nodes.push_back(node);
                }
            }
        }
        return nodes;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        return helper(nums, 0, n - 1);
    }
};