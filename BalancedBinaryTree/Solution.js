/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var helper = function(root) {
    if (root === null) return 0;
    if (root.left === null && root.right === null) return 1;
    var left = helper(root.left);
    var right = helper(root.right);
    if (left != -1 && right != -1) {
        var diff = left > right ? left - right : right - left;
        if (diff <= 1) {
            return 1 + (left > right ? left : right);
        }
    }
    return -1;
};

var isBalanced = function(root) {
    return helper(root) != -1;
};
