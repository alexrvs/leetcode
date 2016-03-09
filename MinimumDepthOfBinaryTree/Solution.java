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
    public int minDepth(TreeNode root) {
        if (root == null) return 0;
        if (root.left == null && root.right == null) return 1;
        int l = -1;
        int r = -1;
        if (root.left != null) l = minDepth(root.left);
        if (root.right != null) r = minDepth(root.right);
        if (l == -1) return 1 + r;
        if (r == -1) return 1 + l;
        return 1 + (l < r ? l : r);
    }
}
