/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* helper(int* nums, int start, int end) {
    if (start > end) return NULL;
    int m = start + (end - start) / 2;
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = nums[m];
    node->left = helper(nums, start, m - 1);
    node->right = helper(nums, m + 1, end);
    return node;
}
 
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;
    return helper(nums, 0, numsSize - 1);
}