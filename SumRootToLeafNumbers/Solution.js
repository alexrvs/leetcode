/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var helper = function (node, prefix, sum) {
    if (node === null) return sum;
    var curVal = prefix * 10 + node.val;
    if (node.left === null && node.right === null) {
        sum += curVal;
    }
    sum = helper(node.left, curVal, sum);
    sum = helper(node.right, curVal, sum);
    return sum;
};

var sumNumbers = function(root) {
    return helper(root, 0, 0);
};
