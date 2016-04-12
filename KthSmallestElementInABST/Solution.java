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
    int m_res;
    int helper(TreeNode node, int n, int k) {
        if (n >= k || node == null) return n;
        int c = helper(node.left, n, k);
        c += 1;
        if (c == k) m_res = node.val;
        return helper(node.right, c, k);
    }

    public int kthSmallest(TreeNode root, int k) {
        helper(root, 0, k);
        return m_res;
    }
}
