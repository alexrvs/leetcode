/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

var helper = function(l, r) {
    if (l === null && r === null) return true;
    if (l === null || r === null) return false;
    if (l.val != r.val) return false;
    return helper(l.left, r.right) && helper(l.right, r.left);
};

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSymmetric = function(root) {
    if (root === null) return true;
    return helper(root.left, root.right);
};
