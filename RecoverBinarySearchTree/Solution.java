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
    public void recoverTree(TreeNode root) {
        TreeNode first = null;
        TreeNode second = null;
        TreeNode pred = null;
        TreeNode prev = null;
        TreeNode cur = root;
        while (cur != null) {
            if (prev != null && prev.val > cur.val) {
                if (first == null) first = prev;
                second = cur;
            }
            
            if (cur.left != null) {
                pred = cur.left;
                while (pred.right != null && pred.right != cur) {
                    pred = pred.right;
                }
                
                if (pred.right == cur) {
                    pred.right = null;
                    prev = cur;
                    cur = cur.right;
                } else {
                    pred.right = cur;
                    cur = cur.left;
                }
            } else {
                prev = cur;
                cur = cur.right;
            }
        }
        
        int val = first.val;
        first.val = second.val;
        second.val = val;
        return;
    }
}