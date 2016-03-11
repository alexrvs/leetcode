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
    private void helper(List<List<Integer>> res, List<Integer> path, TreeNode node, int sum) {
        if (node == null) return;
        path.add(node.val);
        if (node.val == sum && node.left == null && node.right == null) {
            List<Integer> find = new ArrayList<Integer>(path);
            res.add(find);
        } else {
            helper(res, path, node.left, sum - node.val);
            helper(res, path, node.right, sum - node.val);
        }
        path.remove(path.size() - 1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        helper(res, path, root, sum);
        return res;
    }
}
