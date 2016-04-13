/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

var helper = function(node, vals) {
    if (node === null) return;
    helper(node.left, vals);
    vals.push(node.val);
    helper(node.right, vals);
};

/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function(root) {
    var vals = [];
    helper(root, vals);
    console.log(vals.length);
    for (var i = 1; i < vals.length; i++) {
        console.log(vals[i]);
        if (vals[i - 1] >= vals[i]) return false;
    }
    return true;
};
