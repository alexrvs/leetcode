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
    private void helper(List<List<Integer> > res, TreeNode node, int l) {
        if (node == null) return;
        if (l >= res.size()) {
            List<Integer> level = new ArrayList<Integer>();
            res.add(level);
        }
        res.get(l).add(node.val);
        helper(res, node.left, l + 1);
        helper(res, node.right, l + 1);
        return;
    }

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer> > res = new ArrayList<List<Integer> >();
        helper(res, root, 0);
        for (int i = 1; i < res.size(); i += 2) {
            Collections.reverse(res.get(i));
        }
        return res;
    }
}
