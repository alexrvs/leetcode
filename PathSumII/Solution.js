/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

var helper = function(res, path, node, sum) {
    if (node === null) return;
    path.push(node.val);
    if (node.val == sum && node.left === null && node.right === null) {
        var find = path.slice();
        res.push(find);
    } else {
        helper(res, path, node.left, sum - node.val);
        helper(res, path, node.right, sum - node.val);
    }
    path.pop();
};

/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {number[][]}
 */
var pathSum = function(root, sum) {
    var res = [];
    var path = [];
    helper(res, path, root, sum);
    return res;
};
