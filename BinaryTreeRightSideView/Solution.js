/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

var helper = function(view, node, layer) {
    if (null === node) return;
    console.log(view.length);
    if (layer > view.length) view.push(node.val);
    helper(view, node.right, layer + 1);
    helper(view, node.left, layer + 1);
}

/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var rightSideView = function(root) {
    var view = [];
    helper(view, root, 1);
    return view;
};
