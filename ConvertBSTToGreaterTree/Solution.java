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

    int sum;

    private void helper(TreeNode node) {
        if (node == null) return;
        helper(node.right);
        sum += node.val;
        node.val = sum;
        helper(node.left);
        return;
    }

    public TreeNode convertBST(TreeNode root) {
        sum = 0;
        helper(root);
        return root;
    }
}