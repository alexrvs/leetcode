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
    private int helper(TreeNode node) {
        if (node == null) return 0;
        if (node.left == null && node.right == null) return 1;
        int left = helper(node.left);
        int right = helper(node.right);
        int diff = 0;
        if (left != -1 && right != -1) {
            diff = left > right ? left - right : right - left;
            if (diff <= 1) return 1 + (left > right ? left : right);
        }
        return -1;
    }
    public boolean isBalanced(TreeNode root) {
        return (helper(root) != -1);
    }
}
