/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var helper = function(node, vals) {
    if (node === null) return;
    helper(node.left, vals);
    helper(node.right, vals);
    vals.push(node.val);
    return;
};

var postorderTraversal = function(root) {
    var vals = [];
    helper(root, vals);
    return vals;
};
