/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
var res = 0;

var helper = function(node, n, k) {
    if (n >= k || node === null) return n;
    n = helper(node.left, n, k);
    if (++n == k) res = node.val;
    return helper(node.right, n, k);
};

/**
 * @param {TreeNode} root
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    helper(root, 0, k);
    return res;
};
