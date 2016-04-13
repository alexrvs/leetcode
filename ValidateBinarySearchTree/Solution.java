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
    private List<Integer> nums = new ArrayList<Integer>();
    private void traverse(TreeNode node) {
        if (node == null) return;
        traverse(node.left);
        nums.add(node.val);
        traverse(node.right);
    }

    public boolean isValidBST(TreeNode root) {
        traverse(root);
        for (int i = 1; i < nums.size(); i++) {
            if (nums.get(i) <= nums.get(i - 1)) return false;
        }
        return true;
    }
}
