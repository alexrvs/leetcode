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
    private List<Integer> view;

    private void helper(TreeNode node, int layer) {
        if (node == null) return;
        if (layer > this.view.size()) {
            this.view.add(node.val);
        }
        helper(node.right, layer + 1);
        helper(node.left, layer + 1);
        return;
    }

    public List<Integer> rightSideView(TreeNode root) {
        this.view = new ArrayList<Integer>();
        helper(root, 1);
        return this.view;
    }
}
