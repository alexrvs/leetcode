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
    class Sum {
        public int w;
        public int wo;

        Sum(int w, int wo) {
            this.w = w;
            this.wo = wo;
        }
    }

    private Sum helper(TreeNode node) {
        if (node == null) return new Sum(0, 0);
        Sum ls = helper(node.left);
        Sum rs = helper(node.right);
        int w = node.val + ls.wo + rs.wo;
        int sum = 0;
        int wo = 0;
        sum = ls.w + rs.w;
        if (wo < sum) wo = sum;
        sum = ls.wo + rs.w;
        if (wo < sum) wo = sum;
        sum = ls.w + rs.wo;
        if (wo < sum) wo = sum;
        sum = ls.wo + rs.wo;
        if (wo < sum) wo = sum;
        return new Sum(w, wo);
    }

    public int rob(TreeNode root) {
        Sum s = helper(root);
        if (s.w > s.wo) return s.w;
        return s.wo;
    }
}
