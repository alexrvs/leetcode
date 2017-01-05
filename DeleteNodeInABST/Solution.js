/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} key
 * @return {TreeNode}
 */
var deleteNode = function(root, key) {
    let toDel = root;
    let prev = null;
    while (null !== toDel && toDel.val != key) {
        prev = toDel;
        if (key < toDel.val) toDel = toDel.left;
        else toDel = toDel.right;
    }
    if (null === toDel) return root;
    if (null === toDel.left) {
        if (null === prev) {
            root = toDel.right;
        } else {
            if (toDel.val < prev.val) prev.left = toDel.right;
            else prev.right = toDel.right;
        }
    } else {
        if (null === prev) {
            root = toDel.left;
        } else {
            if (toDel.val < prev.val) prev.left = toDel.left;
            else prev.right = toDel.left;
        }
        let pred = toDel.left;
        while (null !== pred && null !== pred.right) {
            pred = pred.right;
        }
        pred.right = toDel.right;
    }
    return root;
};