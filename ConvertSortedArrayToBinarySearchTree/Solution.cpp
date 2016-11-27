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
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        int m = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = helper(nums, start, m - 1);
        node->right = helper(nums, m + 1, end);
        return node;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return NULL;
        return helper(nums, 0, nums.size() - 1);
    }
};