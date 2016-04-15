/**
 * Definition for binary tree with next pointer.
 * function TreeLinkNode(val) {
 *     this.val = val;
 *     this.left = this.right = this.next = null;
 * }
 */

var firstNextHaveChild = function(node) {
    while (node !== null) {
        if (node.left !== null || node.right !== null) return node;
        node = node.next;
    }
    return null;
};

var firstChild = function(node) {
    if (node.left !== null) return node.left;
    return node.right;
};

/**
 * @param {TreeLinkNode} root
 * @return {void} Do not return anything, modify tree in-place instead.
 */
var connect = function(root) {
    if (root === null) return;
    node = root;
    next = null;
    while (node !== null) {
        next = firstNextHaveChild(node.next);
        if (node.left !== null) {
            if (node.right !== null) {
                node.left.next = node.right;
            } else if (next !== null){
                node.left.next = firstChild(next);
            }
        }
        if (node.right !== null && next !== null) {
            node.right.next = firstChild(next);
        }
        node = next;
    }
    connect(root.left);
    connect(root.right);
};
