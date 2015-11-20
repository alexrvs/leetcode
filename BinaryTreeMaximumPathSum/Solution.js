/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

var g_max = 0;

var findMin = function(node) {
    if (node === null) return;
    if (node.val < g_max) g_max = node.val;
    findMin(node.left);
    findMin(node.right);
};

var helper = function(node) {
    if (node === null) return 0;
    var leftSum = helper(node.left);
    var rightSum = helper(node.right);
    var curSum = node.val;
    if (leftSum > 0) curSum += leftSum;
    if (rightSum > 0) curSum += rightSum;
    if (curSum > g_max) g_max = curSum;
    curSum = node.val;
    if (leftSum > rightSum) {
        if (leftSum > 0) curSum += leftSum;
    } else {
        if (rightSum > 0) curSum += rightSum;
    }
    return curSum;
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxPathSum = function(root) {
    g_max = 0;
    findMin(root);
    helper(root);
    return g_max;
};
