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
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return 0;
        int l = 0;
        if (root.left != null && root.left.left == null && root.left.right == null) {
            l = root.left.val;
        } else {
            l = sumOfLeftLeaves(root.left);
        }
        int r = sumOfLeftLeaves(root.right);
        return l + r;
    }
}
