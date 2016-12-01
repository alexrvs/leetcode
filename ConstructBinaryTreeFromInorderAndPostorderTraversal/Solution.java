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
    
    private int search(int val, int[] inorder, int is, int ie) {
        int l = is;
        int r = ie + 1;
        int m = 0;
        for (m = l; m < r; m++) {
            if (inorder[m] == val) break;
        }
        return m;
    }
    
    private TreeNode helper(int[] postorder, int pe, int[] inorder, int is, int ie) {
        if (is > ie || pe < 0) return null;
        int val = postorder[pe];
        TreeNode node = new TreeNode(val);
        int i = search(val, inorder, is, ie);
        node.right = helper(postorder, pe - 1, inorder, i + 1, ie);
        node.left = helper(postorder, pe - 1 - (ie - i), inorder, is, i - 1);
        return node;
    }
    
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return helper(postorder, postorder.length - 1, inorder, 0, inorder.length - 1);
    }
}