/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    if (root === null) return;
    flatten(root.left);
    flatten(root.right);
    if (root.left !== null) {
        var leftTail = root.left;
        while (leftTail.right !== null) {
            leftTail = leftTail.right;
        }
        leftTail.right = root.right;
        root.right = root.left;
        root.left = null;
    }
    return;
};
