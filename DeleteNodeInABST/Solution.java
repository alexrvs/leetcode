/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode toDel = root;
        TreeNode prev = null;
        while (null != toDel && toDel.val != key) {
            prev = toDel;
            if (key < toDel.val) toDel = toDel.left;
            else toDel = toDel.right;
        }
        if (null == toDel) return root;
        if (null == toDel.left) {
            if (null == prev) {
                root = toDel.right;
            } else {
                if (toDel.val < prev.val) prev.left = toDel.right;
                else prev.right = toDel.right;
            }
        } else {
            if (null == prev) {
                root = toDel.left;
            } else {
                if (toDel.val < prev.val) prev.left = toDel.left;
                else prev.right = toDel.left;
            }
            TreeNode pred = toDel.left;
            while (null != pred && null != pred.right) pred = pred.right;
            pred.right = toDel.right;
        }
        return root;
    }
}