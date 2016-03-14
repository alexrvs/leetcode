/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
var res = function(w, wo) {
    this.w = w;
    this.wo = wo;
};

var helper = function(node) {
    if (node === null) return new res(0, 0);
    var ls = helper(node.left);
    var rs = helper(node.right);
    var w = node.val + ls.wo + rs.wo;
    var wo = 0;
    var sum = 0;
    sum = ls.w + rs.w;
    if (wo < sum) wo = sum;
    sum = ls.wo + rs.w;
    if (wo < sum) wo = sum;
    sum = ls.w + rs.wo;
    if (wo < sum) wo = sum;
    sum = ls.wo + rs.wo;
    if (wo < sum) wo = sum;
    return new res(w, wo);
};

/**
 * @param {TreeNode} root
 * @return {number}
 */
var rob = function(root) {
    var s = helper(root);
    if (s.w > s.wo) return s.w;
    return s.wo;
};
