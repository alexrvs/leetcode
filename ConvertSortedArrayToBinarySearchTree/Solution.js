/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
var helper = function(nums, start, end) {
    if (start > end) return null;
    let m = start + ((end - start) >> 1);
    let node = new TreeNode(nums[m]);
    node.left = helper(nums, start, m - 1);
    node.right = helper(nums, m + 1, end);
    return node;
};
 
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
    let size = nums.length;
    if (size === 0) return null;
    return helper(nums, 0, size - 1);
};