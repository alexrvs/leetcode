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
    private int sum = 0;

    private void helper(TreeNode node, int prefix) {
        if (node == null) return;
        int curVal = prefix * 10 + node.val;
        if (node.left == null && node.right == null) {
            sum += curVal;
        }
        helper(node.left, curVal);
        helper(node.right, curVal);
    }

    public int sumNumbers(TreeNode root) {
        sum = 0;
        helper(root, 0);
        return sum;
    }
}
