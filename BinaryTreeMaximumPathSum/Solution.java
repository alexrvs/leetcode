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
    private int max;

    private void findMin(TreeNode node) {
        if (node == null) return;
        if (node.val < max) max = node.val;
        findMin(node.left);
        findMin(node.right);
        return;
    }

    private int helper(TreeNode node) {
        if (node == null) return 0;
        int leftSum = helper(node.left);
        int rigthSum = helper(node.right);
        int curSum = node.val;
        if (leftSum > 0) curSum += leftSum;
        if (rigthSum > 0) curSum += rigthSum;
        if (curSum > max) max = curSum;
        curSum = node.val;
        if (leftSum > rigthSum) {
            if (leftSum > 0) curSum += leftSum;
        } else {
            if (rigthSum > 0) curSum += rigthSum;
        }
        return curSum;
    }

    public int maxPathSum(TreeNode root) {
        max = 0;
        findMin(root);
        helper(root);
        return max;
    }
}
