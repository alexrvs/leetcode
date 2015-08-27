/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

 var helper = function(paths, path, node) {
     if (node === null) return;
     path += node.val;
     if (node.left === null && node.right === null) {
         paths.push(path);
         return;
     }
     if (node.left !== null) helper(paths, path + "->", node.left);
     if (node.right !== null) helper(paths, path + "->", node.right);
     return;
 }

/**
 * @param {TreeNode} root
 * @return {string[]}
 */
var binaryTreePaths = function(root) {
    paths = [];
    path = "";
    helper(paths, path, root);
    return paths;
};
