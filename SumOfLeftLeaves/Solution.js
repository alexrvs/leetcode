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
var sumOfLeftLeaves = function(root) {
    if (root === null) return 0;
    if (root.left === null && root.right === null) return 0;
    var l = 0;
    if (root.left !== null && root.left.left === null && root.left.right === null) {
        l = root.left.val;
    } else {
        l = sumOfLeftLeaves(root.left);
    }
    var r = sumOfLeftLeaves(root.right);
    return l + r;
};
