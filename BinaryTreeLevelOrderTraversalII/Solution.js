/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var helper = function(res, node, l) {
    if (node === null) return;
    if (l >= res.length) res.push([]);
    res[l].push(node.val);
    helper(res, node.left, l + 1);
    helper(res, node.right, l + 1);
    return;
};

var levelOrderBottom = function(root) {
    res = [];
    helper(res, root, 0);
    return res.reverse();
};
