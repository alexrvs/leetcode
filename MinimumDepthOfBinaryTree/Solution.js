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
var minDepth = function(root) {
    if (root === null) return 0;
    if (root.left === null && root.right === null) return 1;
    var l = -1;
    var r = -1;
    if (root.left !== null) l = minDepth(root.left);
    if (root.right !== null) r = minDepth(root.right);
    if (l == -1) return 1 + r;
    if (r == -1) return 1 + l;
    return 1 + (l < r ? l : r);
};
