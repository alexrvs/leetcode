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
var recoverTree = function(root) {
    let f = null;
    let s = null;
    let d = null;
    let prev = null;
    let cur = root;
    while (cur !== null) {
        if (prev !== null && prev.val > cur.val) {
            if (f === null) f = prev;
            s = cur;
        }
        if (cur.left !== null) {
            d = cur.left;
            while (d.right !== null && d.right !== cur) {
                d = d.right;
            }
            
            if (d.right == cur) {
                d.right = null;
                prev = cur;
                cur = cur.right;
            } else {
                d.right = cur;
                cur = cur.left;
            }
        } else {
            prev = cur;
            cur = cur.right;
        }
    }
    let val = f.val;
    f.val = s.val;
    s.val = val;
    return;
};