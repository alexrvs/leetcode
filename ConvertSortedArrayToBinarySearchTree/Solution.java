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
    private TreeNode helper(int[] nums, int start, int end) {
        if (start > end) return null;
        int m = start + (end - start) / 2;
        TreeNode node = new TreeNode(nums[m]);
        node.left = helper(nums, start, m - 1);
        node.right = helper(nums, m + 1, end);
        return node;
    }
    
    public TreeNode sortedArrayToBST(int[] nums) {
        int size = nums.length;
        if (size == 0) return null;
        return helper(nums, 0, size - 1);
    }
}