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

    private List<String> paths = new ArrayList<String>();

    private void helper(String path, TreeNode node) {
        if (node == null) return;
        path += node.val;
        if (node.left == null && node.right == null) {
            paths.add(path);
            return;
        }
        if (node.left != null) {
            helper(path + "->", node.left);
        }
        if (node.right != null) {
            helper(path + "->", node.right);
        }
        return;
    }

    public List<String> binaryTreePaths(TreeNode root) {
        helper("", root);
        return paths;
    }
}
