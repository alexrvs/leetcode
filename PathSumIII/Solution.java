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
    private int helper(TreeNode root, List<Integer> sums, int target) {
        int cnt = 0;
        if (root == null) return cnt;
        int sum = 0;
        for (int i = 0; i < sums.size(); i++) {
            sum = sums.get(i) + root.val;
            if (sum == target) cnt++;
            sums.set(i, sum);
        }
        if (root.val == target) cnt++;
        sums.add(root.val);
        cnt += helper(root.left, sums, target);
        cnt += helper(root.right, sums, target);
        sums.remove(sums.size() - 1);
        for (int i = 0; i < sums.size(); i++) {
            sum = sums.get(i) - root.val;
            sums.set(i, sum);
        }
        return cnt;
    }

    public int pathSum(TreeNode root, int sum) {
        List<Integer> sums = new ArrayList<Integer>();
        return helper(root, sums, sum);
    }
}
