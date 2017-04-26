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
    
    private int tilt;
    
    private int helper(TreeNode node) {
        if (null == node) return 0;
        int l = helper(node.left);
        int r = helper(node.right);
        tilt += Math.abs(l - r);
        return l + r + node.val;
    }
    
    public int findTilt(TreeNode root) {
        this.tilt = 0;
        helper(root);
        return this.tilt;
    }
}