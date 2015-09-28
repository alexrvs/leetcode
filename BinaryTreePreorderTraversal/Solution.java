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
    private void helper(TreeNode node, List<Integer> vals) {
        if (node == null) return;
        vals.add(node.val);
        helper(node.left, vals);
        helper(node.right, vals);
        return;
    }

    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> vals = new ArrayList<Integer>();
        helper(root, vals);
        return vals;
    }
}
