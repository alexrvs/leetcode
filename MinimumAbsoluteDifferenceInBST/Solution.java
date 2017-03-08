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
    
    private int prev;
    private int diff;
    
    private void helper(TreeNode node) {
        if (node == null) return;
        helper(node.left);
        if (this.prev >= 0) {
            int curDiff = node.val - this.prev;
            if (this.diff > curDiff) {
                this.diff = curDiff;
            }
        }
        this.prev = node.val;
        helper(node.right);
        return;
    }
    
    public int getMinimumDifference(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) return 0;
        TreeNode node = root;
        while (node.right != null) node = node.right;
        this.prev = -1;
        this.diff = node.val;
        helper(root);
        return diff;
    }
}