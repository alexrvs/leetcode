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

    private int maxDiameter;

    private int helper(TreeNode node) {
        if (node == null) return 0;
        int l = helper(node.left);
        int r = helper(node.right);
        if (maxDiameter < l + r) maxDiameter = l + r;
        return (l > r ? l : r) + 1;
    }
    
    public int diameterOfBinaryTree(TreeNode root) {
        maxDiameter = 0;
        helper(root);
        return maxDiameter;
    }
}